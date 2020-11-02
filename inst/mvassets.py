import os, sys, shutil

cfgFolder = '~/.config/xenon/'
if sys.platform == 'win32':
    cfgFolder = os.path.join(os.path.expanduser('~'), '.xenon')
cfgFolder = cfgFolder or input(f"Type in path to config folder [{cfgFolder}]:")


os.mkdir(cfgFolder)
dest = os.path.join(__file__, '..', 'assets')
print(f"Copying assets files [{dest}]...")
shutil.copytree(dest, cfgFolder)
print("Finished job.")
sys.exit(0)
