import tools.project as project

project.createContext()
decompiler = project.Decompile()
decompiler.askForFiles()
decompiler.createObjectFiles()
# decompiler.runDecompiler()
project.runDiffer()
