import os


class Paths:
    includeFilePath = os.path.join("include")
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
        f"-I {Paths.asmFilePath}",
        "-mgekko",
        "-c"
    ]
    assemblyFlagString = " ".join([*assemblyFlags])

    compilerFlags = [
        "-gccinc",
        f"-i {Paths.includeFilePath}",
        "-proc gekko",
        "-O3,s",
        "-fp hard",
        "-Cpp_exceptions off",
        "-lang=c++",
        "-c"
    ]
    compilerFlagString = " ".join([*compilerFlags])

    linkerFlags = [
        "-lcf ldscript.lcf"
    ]
    linkerFlagString = " ".join([*linkerFlags])

    assembler = os.path.join(f"{Paths.compilerPath}", "mwasmeppc.exe")
    compiler = os.path.join(f"{Paths.compilerPath}", "mwcceppc.exe")
    linker = os.path.join(f"{Paths.compilerPath}", "mwldeppc.exe")
