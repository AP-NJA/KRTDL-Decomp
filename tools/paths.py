import os


class PathFiles:
    includePath = os.path.join("include")
    sourceFilePath = os.path.join("src")
    asmFilePath = os.path.join("asm")
    toolsPath = os.path.join("tools")

    compilerPath = os.path.join(f"{toolsPath}", "Compiler")
    m2cPath = os.path.join(f"{toolsPath}", "m2c")
    m2ctxPath = os.path.join(f"{toolsPath}", "m2ctx")
    contextFile = os.path.join(f"{toolsPath}", "ctx.c")
    asmDifferPath = os.path.join(f"{toolsPath}", "asm-differ")


class BuildConfig:
    compilerFlags = [
        "-c",
        "-gccinc",
        "-i ./include/ -i ./src/",
        "-proc gekko",
        "-O2,p",
        "-fp hardware",
    ]
    compilerFlagString = " ".join([*compilerFlags])

    compiler = os.path.join(f"{PathFiles.compilerPath}", "mwcceppc.exe")
    linker = os.path.join(f"{PathFiles.compilerPath}", "mwldeppc.exe")
