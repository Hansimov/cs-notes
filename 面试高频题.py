import re

fname = "面试高频题.txt"
fname_out = "面试高频题_纯净.txt"
# with open(fname, encoding="utf-8", mode="r") as rf:
#     txt_str = rf.read()
with open(fname, encoding="utf-8", mode="r") as rf:
    txt_lines = rf.readlines()

res_L = []
cnt = 0
for line in txt_lines:
    new_cnt = re.findall(r"(\d+)\.", line)
    cnt = int(new_cnt[0]) if new_cnt else cnt
    title_link = re.findall(r"\[(.*)\]\((.*)\)", line)
    if len(title_link)==1:
        res_L.append([cnt, title_link[0][0], title_link[0][1]])
    print(cnt, title_link)
# res_L = re.findall(r"\[(.*)\]\((.*)\)", txt_str)
out_str = ""
for item in res_L:
    out_str += "{:<3} {} {}\n".format(item[0], re.sub(r"\s+", "", item[1]), item[2])

with open(fname_out, encoding="utf-8", mode="w") as wf:
    wf.write(out_str)