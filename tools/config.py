import os


class Paths:
    sourceFilePath = os.path.join("src")
    asmFilePath = os.path.join("asm")
    toolsPath = os.path.join("tools")

    compilerPath = os.path.join(f"{toolsPath}", "Compiler")
    m2cPath = os.path.join(f"{toolsPath}", "m2c")
    m2ctxPath = os.path.join(f"{toolsPath}", "m2ctx")
    contextFile = os.path.join(f"{toolsPath}", "ctx.c")
    linkerScript = os.path.join("ldscript.lcf")
    asmDifferPath = os.path.join(f"{toolsPath}", "asm-differ")


class Build:
    assemblyFlags = [
        "-c",
        f"-I {Paths.asmFilePath}"
    ]
    assemblyFlagString = " ".join([*assemblyFlags])

    compilerFlags = [
        "-c",
        "-gccinc",
        f"-i {Paths.sourceFilePath}",
        "-proc gekko",
        "-O3,p",
        "-fp hardware",
    ]
    compilerFlagString = " ".join([*compilerFlags])

    linkerFlags = []
    linkerFlagString = " ".join([*linkerFlags])

    compiler = os.path.join(f"{Paths.compilerPath}", "mwcceppc.exe")
    linker = os.path.join(f"{Paths.compilerPath}", "mwldeppc.exe")
