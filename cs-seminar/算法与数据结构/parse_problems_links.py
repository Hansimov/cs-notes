import requests
import re

fname_en = "tree-lc-en.html"
fname_cn = "tree-lc-cn.html"
in_fname = "树_解析.md"
out_fname = "树_题目.md"

# headers = {
#     "user-agent":"botnet-233"
# }
# url = "https://leetcode.com/tag/tree/"
# req = requests.get(url,headers=headers)
# print(req.status_code)
# with open(fname,"wb",encoding="utf-8") as wf:
#     wf.write(req.content)

with open(fname_en, "r") as rf:
    text_en = rf.read()
with open(fname_cn, "r", encoding="utf-8") as rf:
    text_cn = rf.read()

link_en_bd = "https://leetcode.com{}"
link_cn_bd = "https://leetcode-cn.com{}"

tr_en_L = re.findall(r"<tr[\s\S]*?</tr>", text_en)
tr_cn_L = re.findall(r"<tr[\s\S]*?</tr>", text_cn)
# print(len(tr_L))
lock_str = "&#128274;"


row_en_L = []
for tr in tr_en_L:
    td_L = re.findall("<td [\s\S]*?</td", tr)
    idx_en = int(re.findall(r'value="(\d+)"',td_L[1])[0])
    lock_en = lock_str if re.findall(r'unlock',td_L[2]) else ""
    title_en = re.findall(r'value="([\s\S]*?)"',td_L[2])[0]
    link_en = link_en_bd.format(re.findall(r'href="(.*?)"',td_L[2])[0])
    # link_cn = link_cn_bd.format(re.findall(r'href="(.*?)"',td_L[2])[0])
    acceptance_en = re.findall(r'value="([\s\S]*?)"',td_L[3])[0]
    difficulty_en = re.findall(r'<span.*>([\s\S]*?)</span>',td_L[4])[0]
    row_en_L.append([idx_en, lock_en, title_en, link_en, acceptance_en, difficulty_en])

row_en_L = sorted(row_en_L, key=lambda l:l[0])

row_cn_L = []
for tr in tr_cn_L[:]:
    td_L = re.findall("<td [\s\S]*?</td>", tr)
    idx_cn = int(re.findall(r'>(.*)</td>',td_L[1])[0])
    lock_cn = lock_str if re.findall(r'lock__13du',td_L[0]) else ""
    title_cn = re.findall(r'title="([\s\S]*?)"',td_L[2])[0]
    link_cn = link_cn_bd.format(re.findall(r'href="(.*?)"',td_L[2])[0])
    acceptance_cn = re.findall(r']">(.*?)%</td>',td_L[4])[0]
    difficulty_cn = re.findall(r'<span.*>(.*?)</span>',td_L[5])[0]
    row_cn_L.append([idx_cn, lock_cn, title_cn, link_cn, acceptance_cn, difficulty_cn])
row_cn_L = sorted(row_cn_L, key=lambda l:l[0])

sol_L = []
with open(in_fname, "r", encoding="utf-8") as rf:
    lines = rf.readlines()
    idx, string = None, None
    for line in lines:
        if len(line.strip())==0:
            continue
        tuples = line.strip().split(" ",maxsplit=1)

        if len(tuples)==2 and tuples[0].isdigit():
            if idx != None:
                # print(idx, string)
                sol_L.append([int(idx), string])
            idx, string = tuples
        else:
            string+="<br>"+tuples[0]
    sol_L.append([int(idx), string])

# print(sol_L)
sol_L = sorted(sol_L, key=lambda l:l[0])

md_head = "编号 | 题目 | 通过率 / 难度\n"
md_sep  = "---:|---|---\n"
md_line_bd = "{} {} | [{}]({})<br>[{}]({}) | {}% / {}\n"
md_str = md_head + md_sep
sol_str = "&nbsp; | {} |\n"
sol_ptr = 0
for i in range(len(row_en_L)):
    idx_en, lock_en, title_en, link_en, acceptance_en, difficulty_en = row_en_L[i]
    idx_cn, lock_cn, title_cn, link_cn, acceptance_cn, difficulty_cn = row_cn_L[i]
    if idx_cn != idx_en:
        idx_str = "{}<br>{}".format(idx_en, idx_cn)
    else:
        idx_str = str(idx_en)
    md_str += md_line_bd.format(idx_str, lock_en, title_en, link_en, title_cn, link_cn,  acceptance_en, difficulty_en)
    if sol_ptr<len(sol_L) and sol_L[sol_ptr][0] == idx_en:
        md_str += sol_str.format(sol_L[sol_ptr][1])
        sol_ptr += 1

# print(md_str)
with open(out_fname, "w", encoding="utf-8") as wf:
    wf.write(md_str)

