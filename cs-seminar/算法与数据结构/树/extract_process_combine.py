import os
from PIL import Image

root = "./tree/"
img_path = root + "imgs/"
img_out_path = root + "imgs-out/"
in_pdf = root + "树 combined.pdf"
out_pdf = root + "树 final.pdf"
density = 300
width = -1

# img_path = "./algo4/"
# img_out_path = "./algo4-out/"
# in_pdf = "算法 原书第4版 红宝书.pdf"
# out_pdf = "算法 原书第4版 红宝书【高清】.pdf"
# density = 150
# width = 1500

if not os.path.exists(img_path):
    os.makedirs(img_path)
if not os.path.exists(img_out_path):
    os.makedirs(img_out_path)


extract_cmd = "pdfimages -j \"{}\" \"{}\""
def extract_imgs():
    os.system(extract_cmd.format(in_pdf, img_path))

    for fname in os.listdir(img_path):
        name,ext = os.path.splitext(fname)
        if ext != ".jpg":
            print("Converting {}".format(img_path+fname))
            os.system("magick convert \"{}\" \"{}\"".format(img_path+fname, img_path+name+".jpg"))

def get_max_width():
    global width
    for fname in os.listdir(img_path):
        im = Image.open(img_path+fname)
        tmp_width, _ = im.size
        # print("{} px width of {}".format(tmp_width,fname))
        if width < tmp_width:
            width = tmp_width
    print(width)
    width = max(width, 2000)


# process_cmd = "magick convert -set option:deskew:auto-crop true -deskew 40% -density {} -resize {}x \"{}\" \"{}\""
process_cmd = "magick convert -density {} -contrast -resize {}x \"{}\" \"{}\""
def process_imgs():
    for fname in os.listdir(img_path)[:]:
        name,ext = os.path.splitext(fname)
        out_fname = name+"_out"+".jpg"
        if ext == ".jpg":
            print("Processing {}".format(fname))
            os.system(process_cmd.format(density, width, img_path+fname, img_out_path+out_fname))


combine_cmd = "magick convert \"{}*.jpg\" \"{}\""
def combine_imgs():
    os.system(combine_cmd.format(img_out_path,out_pdf))

# extract_imgs()
get_max_width()
process_imgs()
combine_imgs()