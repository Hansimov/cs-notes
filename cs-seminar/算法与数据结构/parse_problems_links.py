import requests
import re

fname = "tree-lc.html"
out_fname = "tree-lc.txt"
# headers = {
#     "user-agent":"botnet-233"
# }
# url = "https://leetcode.com/tag/tree/"
# req = requests.get(url,headers=headers)
# print(req.status_code)
# with open(fname,"wb",encoding="utf-8") as wf:
#     wf.write(req.content)

with open(fname, "r") as rf:
    text = rf.read()

link_en_bd = "https://leetcode.com{}"
link_cn_bd = "https://leetcode-cn.com{}/solution"

tr_L = re.findall(r"<tr[\s\S]*?</tr>", text)
# print(len(tr_L))

md_head = "编号 | 中文 | 题目 | 通过率 / 难度\n"
md_sep  = "---|---|---|---\n"
md_line_bd = "{} | [中文]({}) | [{}]({}) | {}% / {}\n"
md_str = md_head + md_sep
with open(out_fname, "w") as wf:
    for tr in tr_L[:]:
        td_L = re.findall("<td [\s\S]*?</td", tr)
        # print(len(td_L))
        idx = re.findall(r'value="(\d+)"',td_L[1])[0]
        title = re.findall(r'value="([\s\S]*?)"',td_L[2])[0]
        link_en = link_en_bd.format(re.findall(r'href="(.*?)"',td_L[2])[0])
        link_cn = link_cn_bd.format(re.findall(r'href="(.*?)"',td_L[2])[0])
        acceptance = re.findall(r'value="([\s\S]*?)"',td_L[3])[0]
        difficulty = re.findall(r'<span.*>([\s\S]*?)</span>',td_L[4])[0]
        md_str += md_line_bd.format(idx, link_cn, title, link_en, acceptance, difficulty)
    # print(md_str)
    wf.write(md_str)
        

