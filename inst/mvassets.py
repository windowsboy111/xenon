import os, sys, shutil

cfgFolder = os.path.join(os.path.expanduser('~'), '.config', 'xenon')
if sys.platform == 'win32':
    cfgFolder = os.path.join(os.path.expanduser('~'), '.xenon')
cfgFolder = cfgFolder or input(f"Type in path to config folder [{cfgFolder}]:")


try:
    os.mkdir(cfgFolder)
except FileExistsError: pass
src = os.path.join(os.path.dirname(__file__), '..', 'assets')
print(f"Copying assets files [{src}]...")
shutil.copytree(src, os.path.join(cfgFolder, 'assets'), dirs_exist_ok=True)
print("Finished job.")
sys.exit(0)
