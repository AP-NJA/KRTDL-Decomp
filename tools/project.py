import tools.config as config
import os
import sys
import subprocess
import tkinter
from tkinter.filedialog import askopenfilename


def useWinePrefix() -> str:
    if sys.platform == "darwin" or sys.platform == "linux2":
        return "wine"
    return ""


def createContext():
    subprocess.run(
        f"find {config.Paths.sourceFilePath} -type f -name '*.hh' | sed -e 's/.*/#include \"&\"/' > ctx_includes.c", shell=True
    )
    subprocess.run(
        f"python3.12 {config.Paths.m2ctxPath}/m2ctx.py ctx_includes.c", shell=True
    )


def runDiffer():
    subprocess.run(
        f"python3.12 {config.Paths.asmDifferPath}/diff.py 0x34", shell=True
    )


class Decompile:
    def __init__(self, targetFile: str = "", baseFile: str = ""):
        self.targetFile = targetFile
        self.baseFile = baseFile

    def askForFiles(self):
        self.targetFile = askopenfilename(initialdir="asm")
        self.baseFile = askopenfilename(initialdir="src")

    def createObjectFiles(self):
        subprocess.run(
            f"{useWinePrefix()} {config.Build.compiler} {self.baseFile} {config.Build.compilerFlagString} -o source.o", shell=True
        )
        subprocess.run(
            f"powerpc-eabi-gcc {self.targetFile} -c -o target.o", shell=True
        )

    def runDecompiler(self):
        subprocess.run(
            f"python3.12 {config.Paths.m2cPath}/m2c.py --target ppc-mwcc-c --context {config.Paths.contextFile} --allman --no-unk-inference {self.targetFile} >> {self.baseFile}", shell=True
        )
