1. *program $\rightarrow$ declaration-list*
2. *declaration-list* $\rightarrow$ *declaration-list* *declaration* | *declaration*
3. *declaration* $\rightarrow$ *var-declaration* | *fun-declaration*
4. *var-declaration* $\rightarrow$ *type-specifier* **ID** **;** | *base_type* **ID ** **=** *expression* **;** 
5. *type-specifier* $\rightarrow$ *base-type* | *array-type* 
6. *array-type* $\rightarrow$ *base-type* **[**  **NUM** **]** |   *array-type* **[** **NUM** **]**  | *array-type* **[** **NUM** **]**  **=** **{**  *arr-init-list* **}**   <!-- 我们不支持定义数组的时候方括号内含有表达式 --> <!--支持多维数组-->
7. *arr-init-list* $\rightarrow$  *arr-init-list* **,**  *arr-init* | *arr-init*
8. *arr-init* $\rightarrow$ **{ ** *arr-init-list* **}** | **NUM** <!--注意这里要有方法判断括号的嵌套-->
9. *base_type* $\rightarrow$ **int** | **void** | **double**  |  **float** | **char** | **bool** 
10. *fun-declaration* $\rightarrow$ *type-specifier* **ID ** **(**  *params* **)** *compound-stmt* |      **extern**  *type-specifier* **ID ** **(**  *params* **)**  <!--这里实现了extern函数-->
11. *params* $\rightarrow$ *param-list* | **void**
12. *param-list* $\rightarrow$ *param-list* **,** *param* | *param*
13. *param* $\rightarrow$ *type-specifier* **ID** | *type-specifier* **ID** **[   ]**
14. *compound-stmt* $\rightarrow$ **{** *local-declarations  statement-list* **}**
15. *local-declarations* $\rightarrow$ *local-declarations* *var-declaration* | $\boldsymbol{\epsilon}$
16. *statement-list* $\rightarrow$ *statement-list* *statement* | $\boldsymbol{\epsilon}$
17. *statement* $\rightarrow$ *expression-stmt* | *compound-stmt* | *selection-stmt* | *iteration-stmt* | *return-stmt*
18. *expression-stmt*  $\rightarrow$  *expression* **;** | **;**
19. *selection-stmt* $\rightarrow$ **if** **(** *expression***)** *statement* | **if** **(** *expression* **)** *statement* **else** *statement*
20. *iteration-stmt* $\rightarrow$  *while-stmt* | *for-stmt*
21. *while-stmt* $\rightarrow$ **while** **(** *expression* **)** *statement* 
22. *for-stmt* $\rightarrow$  **for** **(** *expression* **;**  *expression* **;** expression**)** *statement*
23. *return-stmt* $\rightarrow$ **return ;** | **return** *expression* **;**
24. *expression* $\rightarrow$ *var*    **=**    *expression* | *simple-expression*
25. *var* $\rightarrow$ **ID** | **ID** **[** *expression*  **]**
26. *simple-expression* $\rightarrow$ *simple-expression* *logop* *logic-expression* | *logic-expression*
27. *logop* $\rightarrow$ **|| ** | **&&**
28. *logic-expression* $\rightarrow$ *logic-expression* *bitop* *bit-expression* | *bit-expression*
29. *bitop* $\rightarrow$ **|** | **^ ** | **&** 
30. *relop* $\rightarrow$ **<=** | **<** | **>** | **>=** | **==** | **!=**
31. *bit-expression* $\rightarrow$ *bit-expression* *relop* *shift-expression* | *shift-expression*
32. *relop* $\rightarrow$ **<=** | **<** | **>** | **>=** | **==** | **!=**
33. *shift-expression* $\rightarrow$ *shift-expression* *shiop* *additive-expression* | *additive-expression*
34. *shiop*$\rightarrow$ **<<** | **>>**
35. *additive-expression* $\rightarrow$ *additive-expression* *addop* *term* | *term*
36. *addop* $\rightarrow$ **+**|**-**
37. *term* $\rightarrow$ *term* *mulop* *factor* | *factor*
38. *mulop* $\rightarrow$ *****| **/** | **%**
39.  *factor* $\rightarrow$ **!** *factor* | **~** *factor* | -*factor* | *incre*
40. *incre* $\rightarrow$ *incre* **--** | *incre* **++** | *terminal*<!--去掉前缀++和前缀--，后缀的++和--优先级高于‘！-~’,感觉按照yacc的最长字符匹配原则，40和39应该不会有冲突 -->
41. *terminal* $\rightarrow$ **(** *expression* **)** | *var* | *call* | **NUM**
42. *call* $\rightarrow$ **ID** ( *args* )
43. *args* $\rightarrow$ *arg-list* | $\boldsymbol{\epsilon}$
44. *arg-list* $\rightarrow$ *arg-list*    **,**    *expression* | *expression*



<!-- 使用yacc的话，左递归优于右递归 -->



<!-- 无指针运算，无结构体-->

<!--不支持前缀的自增自减操作，自增自减一律视为后缀表达式-->

<!-- 目前似乎对于main函数的位置没有要求，也没有对于函数原型的要求，不知是否需要按照C标准确定main函数位置和函数原型位置-->

<!-- 没有宏定义、引入头文件，使用外部函数实现输入输出-->

<!--使用lex直接处理注释-->