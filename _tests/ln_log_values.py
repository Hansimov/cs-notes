from math import e, log

n = 10
for i in range(2,n+1):
    print("ln{:<2} = {:0<6}".format(i,round(log(i), 4)))

"""
0123456789
lyesswlqbj
lyesxwnqbj
^  ++ ^
"""

"""
ln2  = 0.6931 # 尓 流金岁月
ln3  = 1.0986 # 恕 理解不能
ln4  = 1.3863 # 希 寿比南山
ln5  = 1.6094 # 吾 努力践行
ln6  = 1.7918 # 你 弃甲曳兵
ln7  = 1.9459 # 弃 解析文件
ln8  = 2.0794 # 爸 录取驾校
ln9  = 2.1972 # 救 一加企鹅
ln10 = 2.3026 # 实 色厉而内
"""

print()

for i in range(2,n+1):
    print("lg{:<2} = {:0<6}".format(i,round(log(i,10), 4)))

"""
0123456789
lyesswlqbj
lyesxwnqbj
^  ++ ^
"""

"""
lg2  = 0.3010 # 三氯氧磷
lg3  = 0.4771
lg4  = 0.6021
lg5  = 0.6990
lg6  = 0.7782
lg7  = 0.8451
lg8  = 0.9031
lg9  = 0.9542
lg10 = 1.0000
"""