1. *program $\rightarrow$ declaration-list*
2. *declaration-list* $\rightarrow$ *declaration-list* *declaration* | *declaration*
3. *declaration* $\rightarrow$ *var-declaration* | *fun-declaration*
4. *var-declaration* $\rightarrow$ *type-specifier* **ID  ;**  | *type-specifier* **ID [ NUM ]  ;**
5. *type-specifier* $\rightarrow$ **int** | **void**  ==<!-- maybe char float needed? -->==
6. *fun-declaration* $\rightarrow$ *type-specifier* **ID** **(**  *params* **)** *compound-stmt*
7. *params* $\rightarrow$ *param-list* | **void**
8. *param-list* $\rightarrow$ *param-list* **,** *param* | *param*
9. *param* $\rightarrow$ *type-specifier* **ID** | *type-specifier* **ID** **[   ]**
10. *compount-stmt* $\rightarrow$ **{** *local-declarations  statement-list* **}**
11. *local-declarations* $\rightarrow$ *local-declarations* *var-declaration* | $\boldsymbol{\epsilon}$
12. *statement-list* $\rightarrow$ *statement-list* *statement* | $\boldsymbol{\epsilon}$
13. *statement* $\rightarrow$ *expression-stmt* | *compound-stmt* | *selection-stmt* | *iteration-stmt* | *return-stmt*
14. *expression*$\rightarrow$  *expression* **;** | **;**
15. *selection-stmt* $\rightarrow$ **if** **(** *expression***)** *statement* | **if** **(** *expression* **)** *statement* **else** *statement*
16. *iteration-stmt* $\rightarrow$ **while** **(** *expression* **)** *statement* ==<!--maybe a for loop needed -->==
17. *return-stmt* $\rightarrow$ **return ;** | **return** *expression* **;**
18. *expression* $\rightarrow$ *var*    **=**    *expression* | *simple-expression*
19. *var* $\rightarrow$ **ID** | **ID** **[** *expression*  **]**
20. *simple-expression* $\rightarrow$ *additive-expression* *relop* *additive-expression* | *additive-expression*
21. *relop* $\rightarrow$ **<=** | **<** | **>** | **>=** | **==** | **!=**
22. *additive-expression* $\rightarrow$ *additive-expression* *addop* *term* | *term*
23. *addop* $\rightarrow$ **+**|**-**
24. *term* $\rightarrow$ *term* *mulop* *factor* | *factor*
25. *mulop* $\rightarrow$ ** * **| **/**
26. *factor* $\rightarrow$ **(** *expression* **)** | *var* | *call* | **NUM**
27. *call* $\rightarrow$ **ID** ( *args* )
28. *args* $\rightarrow$ *arg-list* | $\boldsymbol{\epsilon}$
29. *arg-list* $\rightarrow$ *arg-list*    **,**    *expression* | *expression*

<!-- 使用yacc的话，左递归优于右递归 -->

<!-- 无指针类型和相关运算，无结构体，无多维数组 -->

<!-- 无逻辑运算 -->

<!--不支持定义时赋值-->

<!-- 目前似乎对于main函数的位置没有要求，也没有对于函数原型的要求，不知是否需要按照C标准确定main函数位置和函数原型位置-->

<!-- 没有涉及宏定义、引入头文件、以及注释-->
