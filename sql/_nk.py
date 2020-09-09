import os
out_fname = "_nk.sql"
with open(out_fname, mode="w", encoding="utf-8") as wf:

    for fname in os.listdir("."):
        if not fname.startswith("NK"):
            continue
        with open(fname, mode="r", encoding="utf-8") as rf:
            txt = rf.read()
        print("-- " + fname,file=wf)
        print("-"*40, file=wf)
        print(txt, file=wf)
        print("\n\n",file=wf)