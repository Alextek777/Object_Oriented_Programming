#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include "ctime"
#include "string.h"
#include "ctype.h"
#include <iostream>


using namespace std;

char variables[30][30];
bool over = false;
int final_length;

typedef struct Btree
{
    Btree* left;
    Btree* right;
    char sim[100];
};



void sort_function(char function[])
{
    int brackets = 0, add;
    for (int i = 0; i < strlen(function); i++)
    {
        if (function[i] == '(') brackets++;
        if (function[i] == ')') brackets--;

        if (strchr("!@#$%^&", function[i]) != nullptr)
        {
            cout << "found not allowed item : " << function[i] << endl;
            over = true;
            continue;
        }

        if (strchr("+-*/", function[i]) != nullptr && strchr("+-*/\0", function[i + 1]) != nullptr)
        {
            cout << "before and after operation " << function[i] << " must be variables or numbers..." << endl;
            over = true;
            continue;
        }

        if (brackets < 0)
        {
            cout << "clossing brackets are more than openning ones.... " << endl;
            over = true;
            continue;
        }

        if ('/' == function[i] && function[i + 1] == '0')
        {
            cout << "devidint by sezo is not allowed!!!" << endl;
            over = true;
            continue;
        }
    }
    if (brackets != 0)
    {
        cout << "Error with brackets!!!" << endl;
        over = true;
    }
    else
    {
        for (int i = 0; i < strlen(function); i++)
        {
            if ((strchr("+-*/", function[i]) != nullptr) && (strchr(")1234567890zxcvbnmasdfghjklqwertyuiopZXCVBNMASDFGHJKLPOIUYTREWQ", function[i - 1]) == nullptr) && (strchr("1234567890zxcvbnmasdfghjklqwertyuiopZXCVBNMASDFGHJKLPOIUYTREWQ", function[i + 1]) != nullptr))
            {
                add = i;
                for (int j = strlen(function) + 1; j > i; j--)
                    function[j] = function[j - 1];
                function[i] = '0';
            }
        }
    }


}

void matrix_converter(char function[], char fun1[][100])
{
    int j = 0, k = 0, var = 0;
    for (int i = 0; i < strlen(function); i++)
    {
        if (strchr("+-/*()", function[i]) == NULL)
        {
            fun1[k][j] = function[i];
            if (strchr("zxcvbnmasdfghjklqwertyuiopZXCVBNMASDFGHJKLQWERTYUIOP", function[i]) != nullptr)
            {
                variables[k][var] = function[i];
                variables[k + 1][var] = '\0';
                if (strchr("zxcvbnmasdfghjklqwertyuiopZXCVBNMASDFGHJKLQWERTYUIOP", function[i + 1]) == nullptr)
                    var++;
            }
            k++;
            fun1[k][j] = '\0';
            if (strchr("+-/*()", function[i + 1]) != NULL) j++;
        }
        else
        {
            k = 0;
            fun1[k][j] = function[i];
            j++;
        }
        final_length = j;
    }
    fun1[0][j] = '\0';
}

void tree_builder(int from, int to, char fun1[][100], Btree** node)
{
    int k = 0, brackets = 0, n_priority = 100, p_priority = 0, current_priority;

    for (int i = from; i < to; i++)
    {
        if (fun1[0][i] == '(') brackets++;
        if (fun1[0][i] == ')') brackets--;

        if ((brackets == 0) && strchr("+-*/", fun1[0][i]) != nullptr)
        {
            if (fun1[0][i] == '+' || fun1[0][i] == '-') current_priority = 1;
            else current_priority = 2;
            if (current_priority <= n_priority)
            {
                n_priority = current_priority;
                p_priority = i;
            }
        }
    }
    if (n_priority == 100 && from + 1 != to)	tree_builder(from + 1, to - 1, fun1, node);
    if (n_priority != 100)
    {
        *node = new Btree;
        (*(node))->left = nullptr;
        (*(node))->right = nullptr;
        (*(node))->sim[0] = fun1[0][p_priority];
        (*(node))->sim[1] = '\0';
        tree_builder(from, p_priority, fun1, &((*(node))->left));
        tree_builder(p_priority + 1, to, fun1, &((*(node))->right));
    }
    if (from + 1 == to)	//adding number or variable in the end of the Binary tree
    {
        (*(node)) = new Btree;
        (*(node))->left = nullptr;
        (*(node))->right = nullptr;
        int len = 0;
        while (fun1[len][from] != '\0')
        {
            (*(node))->sim[len] = fun1[len][from];
            len++;
        }
        (*(node))->sim[len] = '\0';
    }
}

void del_variable(int column)
{
    int k = 0, last = 0;
    while (variables[0][last] != '\0')
        last++;
    last--;
    while (variables[k][last] != '\0')
    {
        variables[k][column] = variables[k][last];
        k++;
    }
    variables[k][column] = '\0';
    variables[0][last] = '\0';
}




void sort_variables()
{
    int i = 0, j = 1, k = 0;
    bool flag;
    while (variables[0][i] != '\0')
    {
        while (variables[0][j] != '\0')
        {
            flag = true;
            while (variables[k][i] != '\0' && variables[k][j] != '\0' && flag == true)
            {
                if (variables[k][i] != variables[k][j] || variables[k + 1][i] != variables[k + 1][j])  flag = false;
                k++;
            }
            if (flag == true) del_variable(j);
            else j++;
            flag = true;
            k = 0;
        }
        i++;
        j = i + 1;
    }
}




void variables_to_num(Btree* node)
{
    if (node->left != nullptr)variables_to_num(node->left);
    if (strchr("1234567890", node->sim[0]) == nullptr)
    {
        int i = 0, j = 0;
        bool flag;
        while (variables[0][j] != '\0')
        {
            i = 0;
            flag = true;
            while (variables[i][j] != '\0' && node->sim[i] != '\0' && flag == true)
            {
                if (variables[i][j] != node->sim[i]) flag = false;
                if (variables[i + 1][j] != node->sim[i + 1]) flag = false;
                i++;
            }
            if (flag == true)
            {
                i++;
                int k = 0;
                while (variables[i][j] != '\0')
                {
                    node->sim[k] = variables[i][j];
                    k++;
                    node->sim[k] = '\0';
                    i++;
                }
            }
            j++;
        }
    }
    if (node->right != nullptr)variables_to_num(node->right);
    if (strchr("1234567890", node->sim[0]) == nullptr)
    {
        int i = 0, j = 0;
        bool flag;
        while (variables[0][j] != '\0')
        {
            i = 0;
            flag = true;
            while (variables[i][j] != '\0' && node->sim[i] != '\0' && flag == true)
            {
                if (variables[i][j] != node->sim[i]) flag = false;
                if (variables[i + 1][j] != node->sim[i + 1]) flag = false;
                i++;
            }
            if (flag == true)
            {
                i++;
                int k = 0;
                while (variables[i][j] != '\0')
                {
                    node->sim[k] = variables[i][j];
                    k++;
                    node->sim[k] = '\0';
                    i++;
                }
            }
            j++;
        }
    }
}


float calc(Btree* a)
{
    float l, r;
    if (((a->left)->sim[0] == '+') || ((a->left)->sim[0] == '-') || ((a->left)->sim[0] == '*') || ((a->left)->sim[0] == '/'))
        l = calc(a->left);
    else
        l = atoi((a->left)->sim);
    if (((a->right)->sim[0] == '+') || ((a->right)->sim[0] == '-') || ((a->right)->sim[0] == '*') || ((a->right)->sim[0] == '/'))
        r = calc(a->right);
    else
        r = atoi((a->right)->sim);
    switch (a->sim[0])
    {
    case '+':
        return l + r;
    case '-':
        return l - r;
    case '*':
        return l * r;
    case '/':
        if (r == 0)
        {
            cout << "ERROR!!! deviding by zero!!! function will return infinity" << endl;
            return INFINITY;
        }
        return l * 1.0 / r;
    }
}
void count_function_main()      // MAIN FUNCTION HERE
{
    int option;
    char function[100];
    char fun1[100][100];
    variables[0][0] = '\0';
    srand((unsigned)time(NULL));



                                    //enter function-----------------------------------------------------------------------
    strcat(function,"12+13");

    sort_function(function);


    matrix_converter(function, fun1);

    sort_variables();

    Btree* tree = nullptr;

    tree_builder(0, final_length, fun1, &tree);

    char buf[20];
    int mode = 0;
    cout << "if you want to enter variables by yourself press 1 if want make it random press anything else" << endl;
    cin >> mode;
    if (mode == 1)			// inputting variables
    {
        int i = 0, j = 0;
        while (variables[0][j] != '\0')
        {
            cout << "enter variable ";
            while (variables[i][j] != '\0')
            {
                cout << variables[i][j];
                i++;
            }
            cout << ": ";
            i++;
            cin >> buf;
            if (strchr("1234567890", buf[0]) == nullptr)
            {
                cout << "variable must be integer!!!" << endl;
                return;
            }
            else
            {
                for (int k = 0; k < strlen(buf); k++)
                {
                    variables[i][j] = buf[k];
                    i++;
                    variables[i][j] = '\0';
                }
            }
            i = 0;
            j++;
        }
    }
    else                       //random variables
    {
        cout << "random variables: " << endl;
        int i = 0, j = 0, number;
        while (variables[0][j] != '\0')
        {
            while (variables[i][j] != '\0')
            {
                cout << variables[i][j];
                i++;
            }
            number = rand() % 30;
            cout << " : " << number << endl;
            itoa(number, buf, 10);
            i++;
            for (int k = 0; k < strlen(buf); k++)
            {
                variables[i][j] = buf[k];
                i++;
                variables[i][j] = '\0';
            }
            i = 0;
            j++;
        }
    }

    variables_to_num(tree);


    float result;
    result = calc(tree);
    cout << "result : " << result << endl;
    system("pause");
    return;
}





