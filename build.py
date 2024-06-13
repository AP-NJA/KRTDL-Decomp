import io
import os
import sys
from tools.ninja_syntax import Writer

outBuffer = io.StringIO()
ninja = Writer(outBuffer)

fileExtension = ""

if (sys.platform == "darwin" or sys.platform == "linux2"):
    winePrefix = "wine"

ninja.variable("builddir", "objects")
ninja.variable("outdir", "build")
ninja.newline()

compilerPath = os.path.join("tools", "Compiler", "mwcceppc.exe")

ninja.variable("compiler", f"{compilerPath}")
# ninja.variable("compiler", "g++")
ninja.newline()

ninja.rule(
    "cc",
    command=f"{winePrefix} $compiler $ccflags -c $in -o $out",
    description="CC $out"
)
ninja.newline()

ninja.rule(
    "ld",
    command=f"{winePrefix} $compiler $ldflags $in -o $out",
    description="LD $out",
)
ninja.newline()

compilerFlags = [
    "-gccinc",
    "-i ./include/ -i ./src/",
    "-proc gekko",
    "-O2,p",
    "-fp hardware",
]

linkerFlags = []

sourceFiles = [
    os.path.join("src", "Model", "Model.cc"),
    os.path.join("src", "State", "Guard.cc"),
    os.path.join("src", "State", "Intangible.cc"),
    os.path.join("src", "State", "Invincible.cc"),
    # os.path.join("src", "main.cc")
]

targetSourceOutFiles = []

for inFile in sourceFiles:
    _, ext = os.path.splitext(inFile)

    targetOutFile = os.path.join("$builddir", inFile + ".o")
    targetSourceOutFiles.append(targetOutFile)

    ninja.build(
        targetOutFile,
        ext[1:],
        inFile,
        variables={
            "ccflags": " ".join([*compilerFlags])
        }

    )
    ninja.newline()

ninja.build(
    os.path.join('$outdir', f'KRTDL-Decomp{fileExtension}'),
    "ld",
    targetSourceOutFiles,
    variables={
        "ldflags": " ".join([*linkerFlags])
    },
)

ninja.variable("configure", "build.py")
ninja.newline()

ninja.rule(
    "configure",
    command=f'{sys.executable} $configure',
    generator=True,
)
ninja.newline()

ninja.build(
    'build.ninja',
    'configure',
    implicit=[
        '$configure',
        os.path.join('tools', 'ninja_syntax.py'),
    ],
)

with open('build.ninja', 'w') as outFile:
    outFile.write(outBuffer.getvalue())

ninja.close()
