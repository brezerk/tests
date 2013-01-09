/***************************************************************************
 *   Copyright (C) 2013 by Alexey S. Malakhov                              *
 *   brezerk@gmail.com                                                     *
 *                                                                         *
 *   This program is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 ***************************************************************************/

/*
 * pointers.c
 *
 * A simple poiters use cases.
 * With gdb debug output.
 *
 */

#include <iostream>
#include <stdlib.h>

void foo0(int a0){
	std::cout << a0 << std::endl;
	return;
}
void foo1(int &a1){
	std::cout << a1 << std::endl;
	return;
}
void foo2(int *a2){
	std::cout << a2 << std::endl;
	return;
}

int main(){
	/*
	 * Val: 10
	 * Adr: (int *)  0x7fffffffdfa4
	 */
	int a = 10;
	/*
	 * Val: (int *)  0x7fffffffdfa4 
	 * Adr: (int **) 0x7fffffffdfa8
	 */
	int *b = &a;
	
	/*
	 * Copy a -> a0
	 *
	 * Val: 10
	 * Adr: (int *) 0x7fffffffdf8c
	 */
	foo0(a); 
	//foo0(&a);  invalid conversion from ‘int*’ to ‘int’
	//foo0(*a);  invalid type argument of unary ‘*’ (have ‘int’)

	/*
	 * Copy an adress of a and place it to a1
	 *
	 * Val: (int &) @0x7fffffffdfa4: 10
	 * Adr: (int *) 0x7fffffffdfa4
	 */
	foo1(a);
	//foo1(&a);  invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘int*’
	//foo1(*a);  invalid type argument of unary ‘*’ (have ‘int’)

	//foo2(a);   invalid conversion from ‘int’ to ‘int*’
	/*
	 * Create a pointer a2 to address of a
	 *
	 * Val: (int *) 0x7fffffffdfa4
	 * Adr: (int **) 0x7fffffffdf88
	 */
	foo2(&a);
	//foo2(*a);  invalid type argument of unary ‘*’ (have ‘int’)

	//foo0(b);   invalid conversion from ‘int*’ to ‘int’
	//foo0(&b);  invalid conversion from ‘int**’ to ‘int’
	/*
	 * Take an a value of pointer and copy it to a0
	 * i.e.: b -> &a and *b = 10
	 * 
	 * Val: 10
	 * Adr: (int *) 0x7fffffffdf8c
	 *
	 */
	foo0(*b);
	
	//foo1(b);   invalid initialization of reference of type ‘int&’ from expression of type ‘int*’
	//foo1(&b);  invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘int**’
	/*
	 * Take an a value of a pointer and copy it's address to a1
	 *
	 * Val: (int &) @0x7fffffffdfa4: 10
	 * Adr: (int *) 0x7fffffffdfa4
	 *
	 */
	foo1(*b);
	
	// pointer to 10
	/*
	 * Take an a pointer and copy it's addres to a2 
	 *
	 * Val: (int *) 0x7fffffffdfa4
	 * Adr: (int **) 0x7fffffffdf88
	 */
	foo2(b);
	//foo2(&b);  cannot convert ‘int**’ to ‘int*’ for argument ‘1’ to ‘void foo2(int*)’
	//foo2(*b);  invalid conversion from ‘int’ to ‘int*’

	return 0;
}

