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
 * singleton.cpp
 * Simple singleton example
 *
 */

#include <iostream>

class A {
	protected:
		A() {}
		A(const A&);
		A& operator=(const A&);
		~A();
		static A* instance;
	private:
		int a_;
	public:
		static A* getInstance(void){
			return instance ? instance : (instance = new A());
		}
		void setA(int a) { a_ = a; }
		int getA(void) { return a_; }
};

A* A::instance(NULL);

int main(){
	A *foo = A::getInstance();
	foo->setA(10);
	std::cout << "foo:" << foo->getA() << std::endl;

	A *bar = A::getInstance();
	std::cout << "bar:" << bar->getA() << std::endl;

	return 0;
}
