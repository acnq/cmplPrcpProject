# our syntax

1. *program $\rightarrow$ declaration-list*
2. *declaration-list* $\rightarrow$ *declaration-list* *declaration* | *declaration*
3. *declaration* $\rightarrow$ *var-declaration* | *fun-declaration*
4. *var-declaration* $\rightarrow$ *base-type* *id-list* **;** | *base-type* **ID** *array-post* **;** | *base-type* **ID** *array-post* **=** **{** *array-const-list* **}**  **;**
5. *id-list* $\rightarrow$ *id-list* **,** **ID** | *id-list* **,** **ID** **=**  *expression* | **ID** | **ID** **=** *expression*
6. *array-const-list* $\rightarrow$ *array-const-list* **,** *single* | *single*
7. *base_type* $\rightarrow$ **int** |  **double**  |  **float** | **char** | **bool**
8. *fun-declaration* $\rightarrow$ *base-type* **ID** **(**  *params* **)** *compound-stmt* |  **void**    **ID** **(**  *params* **)** *compound-stmt*  | **extern**  *base-type* **ID** **(**  *params* **)** | **extern**  **void** **ID** **(**  *params* **)**  <!--这里实现了extern函数-->
9. *params* $\rightarrow$ *param-list* | **void**
10. *param-list* $\rightarrow$ *param-list* **,** *param* | *param*
11. *param* $\rightarrow$ *base-type* **ID** | *base-type* **ID** *array-post-param*
12. *array-post-param* $\rightarrow$  **[** **]** | **[** **NUM** **]** | *array-post-param* **[** **NUM** **]**
13. *compound-stmt* $\rightarrow$ **{** *local-declarations  statement-list* **}** | **{** *local-declarations* **}** |   **{** *statement-list* **}** | **{** **}**
14. *local-declarations* $\rightarrow$ *local-declarations* *var-declaration* | *var-declaration*
15. *statement-list* $\rightarrow$ *statement-list* *statement* | *statement*
16. *statement* $\rightarrow$ *expression-stmt* | *compound-stmt* | *selection-stmt* | *iteration-stmt* | *return-stmt*
17. *expression-stmt*  $\rightarrow$  *expression* **;** | **;**
18. *selection-stmt* $\rightarrow$ **if** **(** *expression* **)** *statement* | **if** **(** *expression* **)** *statement* **else** *statement*
19. *iteration-stmt* $\rightarrow$  *while-stmt* | *for-stmt*
20. *while-stmt* $\rightarrow$ **while** **(** *expression* **)** *statement*
21. *for-stmt* $\rightarrow$  **for** **(** *expression* **;**  *expression* **;** *expression* **)** *statement*
22. *return-stmt* $\rightarrow$ **return ;** | **return** *expression* **;**
23. *expression* $\rightarrow$ *var*    *assop*    *expression* | *operand*
24. *assop* $\rightarrow$ **=** | **+=** | **-=** | **\*=** | **/=**| **%=**|**^=** | **&=** | **|=** | **<<=** | **>>=**
25. ==*var* $\rightarrow$ **ID** | **ID** **[** *expression*  **]**== 注意修改
26. *operand* $\rightarrow$ *operand* **||** *operand* | *operand* **&&** *operand* | *operand* **|** *operand* |*operand* **^** *operand* | *operand* **&** *operand* | *operand* **=** *operand* | *operand* **!=** *operand*| *operand* **<** *operand* | *operand* **>** *operand* | *operand* **<=** *operand* | *operand* **>=** *operand*  | *operand* **<<** *operand* | *operand* **>>** *operand* | *operand* **+** *operand*  | *operand* **-** *operand* | *operand* **\*** *operand* | *operand* **/** *operand* | *operand* **%** *operand* | *prefix* **(** *operand* **)** | **(** *operand* **)** | *prefix* *single* | *single*
27. *prefix* $\rightarrow$ **!** | **~** | **-**
28. *single* $\rightarrow$ *var* | *call* | **NUM**| **DOUBLE** | **CHAR** | **TURE** |  **FALSE**
29. *call* $\rightarrow$ **ID** **(** *args* **)**
30. *args* $\rightarrow$ *arg-list* | $\boldsymbol{\epsilon}$
31. *arg-list* $\rightarrow$ *arg-list*    **,**    *expression* | *expression*

以下下均为注释：

<!-- 26. *simple-expression* $\rightarrow$ *simple-expression* *logop* *logic-expression* | *logic-expression*

27. *logop* $\rightarrow$ **||** | **&&**
28. *logic-expression* $\rightarrow$ *logic-expression* *bitop* *bit-expression* | *bit-expression*
29. *bitop* $\rightarrow$ **|** | **^** | **&**
30. *bit-expression* $\rightarrow$ *bit-expression* *relop* *shift-expression* | *shift-expression*
31. *relop* $\rightarrow$ **<=** | **<** | **>** | **>=** | **==** | **!=**
32. *shift-expression* $\rightarrow$ *shift-expression* *shiop* *additive-expression* | *additive-expression*
33. *shiop*$\rightarrow$ **<<** | **>>**
34. *additive-expression* $\rightarrow$ *additive-expression* *addop* *term* | *term*
35. *addop* $\rightarrow$ **+**|**-**
36. *term* $\rightarrow$ *term* *mulop* *factor* | *factor*
37. *mulop* $\rightarrow$ **\***| **/** | **%**
38. *factor* $\rightarrow$ **!** *factor* | **~** *factor* | **-** *factor* | *incre*
39. *incre* $\rightarrow$ *incre* **--** | *incre* **++** | *terminal* 去掉前缀++和前缀--，后缀的++和--优先级高于‘！-~’,感觉按照yacc的最长字符匹配原则，40和39应该不会有冲突 

40. *terminal* $\rightarrow$ **(** *expression* **)** | *var* | *call* | **NUM**| **DOUBLE** | **CHAR** | **TURE** |  **FALSE**-->

<!-- 使用yacc的话，左递归优于右递归 -->

<!-- 无指针运算，无结构体-->

<!-- 目前似乎对于main函数的位置没有要求，也没有对于函数原型的要求，不知是否需要按照C标准确定main函数位置和函数原型位置-->

<!-- 没有宏定义、引入头文件，使用外部函数实现输入输出-->

<!--使用lex直接处理注释-->

<!--Lex的注释法 https://cs.gmu.edu/~henryh/330/Lex/comments.html -->
