import requests
import re

fname = "jz_tree.html"
out_fname = "jz_tree.md"

with open(fname, "r", encoding="utf-8") as rf:
    text = rf.read()

link_bd = "https://www.nowcoder.com{}"

tr_L = re.findall(r"<tr[\s\S]*?</tr>", text)

row_L = []
for tr in tr_L[1:]:
    td_L = re.findall("<td[\s\S]*?</td>", tr)
    idx = int(re.findall(r'JZ(\d+)', td_L[0])[0])
    title = re.findall(r'title">([\s\S]*?)</span>',td_L[1])[0].strip()
    link = link_bd.format(re.findall(r'data-href="(.*?)"', tr)[0])
    difficulty = re.findall(r'<td>([\s\S]*?)</td>',td_L[3])[0]
    acceptance = re.findall(r'<td>([\s\S]*?)</td>',td_L[4])[0]
    row_L.append([idx, title, link, acceptance, difficulty])

row_L = sorted(row_L, key=lambda l:l[0])

md_head = "编号 | 题目 | 通过率 / 难度\n"
md_sep  = "---:|---|---\n"
md_line_bd = " {} | [{}]({}) | {} / {}\n"
md_str = md_head + md_sep
for i in range(len(row_L)):
    idx, title, link, acceptance, difficulty = row_L[i]
    md_str += md_line_bd.format(idx, title, link, acceptance, difficulty)

with open(out_fname, "w", encoding="utf-8") as wf:
    wf.write(md_str)

