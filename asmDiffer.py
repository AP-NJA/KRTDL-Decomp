import tools.project as project

decompiler = project.Decompile()
decompiler.askForFiles()
decompiler.createObjectFiles()
project.runDiffer()
