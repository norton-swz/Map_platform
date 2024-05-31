import os
import shutil

src = "E:\\Source\\cpp\\BasicInterface\\BasicInterface\\image\\Level_1\\test.png"

for i in range(1, 41):
    for j in range(1, 41):
        dst = "E:\\Source\\cpp\\BasicInterface\\BasicInterface\\Level_1\\" + "Tile_01_" + str(i).zfill(3) + "_" + str(j).zfill(3) + ".png"
        shutil.copy(src, dst)