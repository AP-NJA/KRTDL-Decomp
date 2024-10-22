import os
import subprocess
import tools.project as project
import tools.config as config

sourceFiles = [
    os.path.join("src", "Character", "HP.cc"),
    os.path.join("src", "Hero", "Hero.cc"),
    os.path.join("src", "Hero", "State", "Guard.cc"),
    os.path.join("src", "Hero", "State", "Intangible.cc"),
    os.path.join("src", "Hero", "State", "Invincible.cc")
]
sourceFileString = " ".join([*sourceFiles])

objectFiles = []

print("Creating objects folder...")
subprocess.run(
    "mkdir -p objects", shell=True
)

print("Compiling source files...")

for index, sourceFile in enumerate(sourceFiles):
    paths = os.path.dirname(sourceFile)
    pre, ext = os.path.splitext(sourceFile)

    objectFiles.append(f"{pre}.o")

    print(f"{index + 1}/{len(sourceFiles)}: {sourceFile}")
    subprocess.run(
        f"{project.useWinePrefix()} {config.Build.compiler} {sourceFile} {config.Build.compilerFlagString}", shell=True
    )

    subprocess.run(
        f"mkdir -p objects/{paths}", shell=True
    )
    subprocess.run(
        f"mv {os.path.basename(objectFiles[index])} objects/{objectFiles[index]}", shell=True
    )

objectFileString = " objects/".join([*objectFiles])

print(f"{objectFileString}")

subprocess.run(
    f"{project.useWinePrefix()} {config.Build.linker} objects/{objectFileString} {config.Build.linkerFlagString} -o linkerFlagString.elf", shell=True
)

# This looks really bad upon closer inspection but whatever LOL
