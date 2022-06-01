from PIL import Image
import glob
import os

out_dir = 'D:\ComputerGraphics\\3-D-LinearTransformation\Output'
cnt = 0
for img in glob.glob('./*.bmp'):
    name = (img.split("\\")[1]).split(".")[0]
    Image.open(img).save(
        os.path.join(out_dir, name + '.png'))
    cnt += 1

for img in glob.glob('./*.bmp'):
    os.remove(img)
