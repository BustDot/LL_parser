# LL(1) Grammar Analyzer

### 使用方法

要使用该程序，只需在命令行中运行该程序。程序会从`assets`目录下的`grammar.txt`与`lex.txt`读取文法规则与待分析的句子并输出分析过程至控制台中，同时将中间过程输出至当前目录下的`log.txt`。

```
$  .\LL_parser
```

### 实现

对于LL(1)语法分析，需要经历以下步骤：

1. 消除语法左递归：`void dealGrammers();`
2. 提取语法左公共因子：`void dealLeftCommonGrammers();`
3. 计算语法的first与follow集: `makeFirst(); makeFollow();`
4. 生成预测分析表：`makeTable();`
5. 根据预测分析表与分析句子生成分析栈：`void analyzer(vector<string> &text);`

### 示例

grammar.txt:

```
statement-->if-stmt | other
if-stmt-->if ( exp ) statement else-part
else-part-->else statement | #
exp-->0 | 1
```

Lex.txt:

```
if ( 0 ) if ( 1 ) other else other
```

Result:

```
1	$ if-stmt 	 if ( 0 ) if ( 1 ) other else other $	statement-> if-stmt
2	$ else-part statement ) exp ( if 	 if ( 0 ) if ( 1 ) other else other $	if-stmt-> if ( exp ) statement else-part
3	$ else-part statement ) exp ( 	 ( 0 ) if ( 1 ) other else other $	match
4	$ else-part statement ) exp 	 0 ) if ( 1 ) other else other $	match
5	$ else-part statement ) 0 	 0 ) if ( 1 ) other else other $	exp-> 0
6	$ else-part statement ) 	 ) if ( 1 ) other else other $	match
7	$ else-part statement 	 if ( 1 ) other else other $	match
8	$ else-part if-stmt 	 if ( 1 ) other else other $	statement-> if-stmt
9	$ else-part else-part statement ) exp ( if 	 if ( 1 ) other else other $	if-stmt-> if ( exp ) statement else-part
10	$ else-part else-part statement ) exp ( 	 ( 1 ) other else other $	match
11	$ else-part else-part statement ) exp 	 1 ) other else other $	match
12	$ else-part else-part statement ) 1 	 1 ) other else other $	exp-> 1
13	$ else-part else-part statement ) 	 ) other else other $	match
14	$ else-part else-part statement 	 other else other $	match
15	$ else-part else-part other 	 other else other $	statement-> other
16	$ else-part else-part 	 else other $	match
17	$ else-part statement else 	 else other $	else-part-> else statement
18	$ else-part statement 	 other $	match
19	$ else-part other 	 other $	statement-> other
20	$ else-part 	 $	match
21	$ # 	 $	else-part-> #
22	$ 	 $	match
23			match
```

Log.txt:

```
Scanning...>>>>	statement-->if-stmt | other
Scanning...>>>>	if-stmt-->if ( exp ) statement else-part
Scanning...>>>>	else-part-->else statement | #
Scanning...>>>>	exp-->0 | 1
-------------原本语法如下---------------
1 :::>>> statement==> if-stmt | other
2 :::>>> if-stmt==> if ( exp ) statement else-part
3 :::>>> else-part==> else statement | #
4 :::>>> exp==> 0 | 1
非终结符号如下:
statement if-stmt else-part exp 
终结符号如下:
other if ( ) else # 0 1 
非终结符号个数:4
终结符号个数:8
1 :::>>> statement==> if-stmt | other
2 :::>>> if-stmt==> if ( exp ) statement else-part
3 :::>>> else-part==> else statement | #
4 :::>>> exp==> 0 | 1
非终结符号如下:
statement if-stmt else-part exp 
终结符号如下:
other if ( ) else # 0 1 
非终结符号个数:4
终结符号个数:8
-------------去除左递归后---------------
1 :::>>> statement==> if-stmt | other
2 :::>>> if-stmt==> if ( exp ) statement else-part
3 :::>>> else-part==> else statement | #
4 :::>>> exp==> 0 | 1
非终结符号如下:
statement if-stmt else-part exp 
终结符号如下:
other if ( ) else # 0 1 
非终结符号个数:4
终结符号个数:8
-------------去除多余项后---------------
1 :::>>> statement==> if-stmt | other
2 :::>>> if-stmt==> if ( exp ) statement else-part
3 :::>>> else-part==> else statement | #
4 :::>>> exp==> 0 | 1
非终结符号如下:
statement if-stmt else-part exp 
终结符号如下:
other if ( ) else # 0 1 
非终结符号个数:4
终结符号个数:8
-------------去除左公因子后---------------
1 :::>>> statement==> if-stmt | other
2 :::>>> if-stmt==> if ( exp ) statement else-part
3 :::>>> else-part==> else statement | #
4 :::>>> exp==> 0 | 1
非终结符号如下:
statement if-stmt else-part exp 
终结符号如下:
other if ( ) else # 0 1 
非终结符号个数:4
终结符号个数:8
FIRST(else-part)={#,else}
FIRST(exp)={0,1}
FIRST(if-stmt)={if}
FIRST(statement)={if,other}
FOLLOW(else-part)={$,else}
FOLLOW(exp)={)}
FOLLOW(if-stmt)={$,else}
FOLLOW(statement)={$,else}

```

