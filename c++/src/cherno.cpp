//#include<iostream>
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	std::cin.get();
//}

//11.30
//1.引用：& -->常用在函数参数传递，使代码易于阅读
// 
//  -->特点:
//1>别名：引用通常是为一个已有变量提供另一个名字，直接操作引用就等同于操作原变量
//2>指向内存地址：引用指向变量在内存中的地址，而非值本身
//3>共享修改：通过引用修改数据时，原始变量会同步变化
//4>声明时需要初始化，且之后无法更改指向
//5>引用不是变量，不在内存中创建空间

//#include<iostream>
//#define LOG(x) std::cout<<x<<std::endl
//
//void increment(int& ref)
//{
//	ref = 2;
//}
//
//int main()
//{
//	int a = 5;
//	//int& ref = a;
//	//ref = 2;
//	increment(a);
//	LOG(a);
//}

//2.类：class  -->使代码简洁易懂
//  是C++中面向对象编程（OOP）的核心概念,它是用户自定义的类型
//  由类类型组成的变量称为对象
// 
//  -->类的基本组成:
//
//   1>数据成员（成员变量）：
//      用于存储对象的属性或状态
//      可以是基本数据类型、类类型或指针
// 
//   2>成员函数：（也叫作方法）
//      操作数据成员的函数，定义对象的行为
//      包括普通函数和构造函数、析构函数等特殊成员函数
// 
//   3>访问权限：
//      控制类成员的访问范围
//       有三种访问修饰符：
		//public: 公有成员，类外可以访问。
		//private: 私有成员，仅类内部可以访问（默认）。
		//protected: 受保护成员，仅类及其派生类可以访问。

//#include<iostream>
//class player
//{
//public:  //默认为private
//	int x, y;
//	int speed;
//
//	void move(int xa, int ya)  //方法
//	{
//		x += xa * speed;
//		y += ya * speed;
//	}
//};
//
//int main()
//{
//	player player;
//	player.x = 4;
//	player.y = 2;
//	player.speed = 1;
//	player.move(1, -1);
//}

//3.struct vs class:
// 在c++中，struct和class只有可见性的区别，struct的可见性默认为public,而class的可见性默认为private
//          但通常，当只有若干个成员变量时用struct，涉及函数（方法）时用class
// 
//在c中：stuct只能表示变量
//在c++中，struct能包含函数及其他功能（与class相同 )


//12.1
//1.如何写一个c++类：( log类 )
//#include<iostream>
//class Log
//{
//public:
//	const int LogLevelError = 0;
//	const int LogLevelWarning = 1;
//	const int LogLevelInfo = 2;
//private:
//	int m_LogLevel = 2;
//public:
//	void SetLevel(int level)
//	{
//		m_LogLevel = level;
//	}
//
//	void Error(const char* message)
//	{
//		if(m_LogLevel>=LogLevelError)
//		    std::cout << "[Error]:" << message << std::endl;
//	}
//	void Warn(const char* message)
//	{
//		if(m_LogLevel >= LogLevelWarning)
//		   std::cout <<"[Warning]:"<< message << std::endl;
//	}
//	void Info(const char* message)
//	{
//		if (m_LogLevel >= LogLevelInfo)
//		    std::cout << "[Info]:" << message << std::endl;
//	}
//};
//
//int main()
//{
//	Log log;
//	log.SetLevel(log.LogLevelWarning);
//
//	log.Error("hello!");
//	log.Warn("hello!");
//	log.Info("hello!");
//	std::cin.get();
//}


//2.关键字static:(修饰变量或函数)

//1>在类和结构体之外:
      //表示变量或函数是内部链接的,不能在另一个c++文件中使用
      //在头文件中包含 static 变量，会导致每个包含头文件的编译单元都创建一个独立的变量实例
      
//补充:实例:<1>类:类是模板,而实例是具体实现,一个类可以有多个实例
         // <2>变量:一个变量在程序运行时分配了存储空间并存储了实际值，这被称为变量实例



//2>*****在类和结构体之内***********:
     //static 修饰变量:表示它们属于整个类，而不属于某个对象
         //<1>所有类的实例共享同一份 x 和 y 的存储空间
         //<2>在类中声明后，必须在类外定义和初始化

    //static 修饰函数:静态函数不依赖于任何类的实例，可以直接通过类名调用
         // **只能访问类的静态成员，不能直接访问非静态成员


//1.无static修饰:
//#include<iostream>
//struct Entity
//{
//    int x, y;
//    
//    void print()
//    {
//        std::cout << x << "," << y << std::endl;
//    }
//};
//
//int main()
//{
//    Entity e;
//    e.x = 2;
//    e.y = 3;
//
//    Entity e1;
//    e1.x = 5;
//    e1.y = 8;
//
//    e.print();
//    e1.print();
//
//}

//2. static 修饰变量
//#include<iostream>
//struct Entity
//{
//    static int x, y;  //只是声明,没有定义和初始化
//
//    void print()
//    {
//        std::cout << x << "," << y << std::endl;
//    }
//};
//
////****在类外部定义静态变量时，需要加上类的作用域限定符 Entity::
////这里是定义,没有初始化
//int Entity::x;
//int Entity::y;
//
//int main()
//{
//    /*Entity e;
//    e.x = 2;
//    e.y = 3;*/
//    Entity::x = 2;   //这里是初始化
//    Entity::y = 3;
//
//    /*Entity e1;
//    e1.x = 5;
//    e1.y = 8;*/
//    Entity::x = 5;
//    Entity::y = 8;
//
//    //如果一个类中存在静态变量和非静态方法，
//    //要在类外引用非静态方法，必须先创建该类的实例，然后通过该实例调用非静态方法
//    Entity e;
//    e.print();
//
//}

//3.static 修饰方法:
// 
//静态方法无法直接访问非静态变量，因为静态方法没有实例上下文
//如果需要在静态方法中访问非静态变量，必须通过将实例对象作为参数传递给静态方法来实现
//#include<iostream>
//struct Entity
//{
//    int x, y;
//    
//    static void print(Entity& e)
//    {
//        std::cout << e.x << "," << e.y << std::endl;
//    }
//};
//
//int main()
//{
//    Entity e;
//    e.x = 2;
//    e.y = 3;
//
//    Entity e1;
//    e1.x = 5;
//    e1.y = 8;
//
//    Entity::print(e);
//    Entity::print(e1);
//}


//12.2
//1.enum(枚举类型）：本质上是一组数值（整数）的集合，使代码易于管理和阅读
// 
//#include<iostream>
//enum example: unsigned char  //可以指定底层类型（必须是整型家族，默认是int） -->节约空间，满足特定需求
//{
//    A,  //如果不初始化，默认值为0，并依次递增
//    B,
//    C
//};
//
//int main()
//{
//    int value1 = A;
//    example value2 = A; //使用enum类型定义变量时，只能赋enum中的值
//}

//改写log类：
//#include<iostream>
//class Log
//{
//public:
//	enum level
//	{
//		levelError=0,
//		levelWarning,
//		levelInfo
//	};
//private:
//	level m_LogLevel = levelInfo;
//public:
//	void SetLevel(level level)
//	{
//		m_LogLevel = level;
//	}
//
//	void Error(const char* message)
//	{
//		if (m_LogLevel >= levelError)
//			std::cout << "[Error]:" << message << std::endl;
//	}
//	void Warn(const char* message)
//	{
//		if (m_LogLevel >= levelWarning)
//			std::cout << "[Warning]:" << message << std::endl;
//	}
//	void Info(const char* message)
//	{
//		if (m_LogLevel >= levelInfo)
//			std::cout << "[Info]:" << message << std::endl;
//	}
//};
//
//int main()
//{
//	Log log;
//	log.SetLevel(Log::levelWarning); 
//	//在 C++ 中，enum 类型（枚举）成员被视为类的静态成员，
//	// 属于整个类而不是某个具体的对象,这意味着它们在类的所有实例中都是共享的
//	// 因此，访问枚举成员时需要通过类名（Log::levelError）而不是实例对象（log.levelError）来进行
//
//	//但是，某些情况下，log.levelError也可以，
//	//enum level 是一个普通的枚举类型（没有使用 enum class）
//	// 在 C++ 中，普通的枚举会把它的成员提升到类的作用域中
//	// 因此，尽管你在类 Log 内部定义了 enum level，
//	// 编译器会把 levelError、levelWarning 和 levelInfo 当作类的成员来处理
//	// 
//	//但如果是强类型枚举（enum class）：其成员会被严格限定在枚举的作用域内，
//	// 不能通过对象或类名直接访问，必须使用 Log::levelWarning。
//
//
//	log.Error("hello!");
//	log.Warn("hello!");
//	log.Info("hello!");
//	std::cin.get();
//}


//12.4
//1.构造函数：
// 一种类中的特殊的方法，只有在创建了类的实例时才运行，主要用途是初始化类
//当类中没有显式定义构造函数时，编译器会自动生成一个默认构造函数，使得类能够被实例化
//如果显式地删除（= delete）构造函数，就无法通过默认构造实例化对象
//构造函数可以有多个

//#include<iostream>
//#include<iomanip>  //std::fixed  -->将浮点数的输出格式设置为固定的小数点格式
//                  //std::setprecision(2)：设置输出的浮点数精度为 2，即保留 2 位小数         
//class Entity
//{
//public:
//    float X, Y;
//
//    //显式定义构造函数，函数名是类名，没有返回值类型
//    Entity()
//    {
//        X = 0.0f;
//        Y = 0.0f;
//    }
//
//    //函数重载：即多个函数名相同，但参数类型，顺序，数量不同（返回值类型不能区分函数重载）
//    Entity(float x, float y)
//    {
//        X = x;
//        Y = y;
//    }
//
//    void print()
//    {
//        std::cout << X << " " << Y << std::endl;  //std::cout默认以int格式输出
//        //std::cout << std::fixed << std::setprecision(2) << X << " " << Y << std::endl;
//    }
//};
//int main()
//{
//    /*Entity e;
//    std::cout << e.X << std::endl;*/  //e.X没有初始化，会报错
//
//    //使用Entity()构造函数
//    Entity e;
//    e.print();
//    //使用Entity(float x, float y)构造函数
//    Entity e1(10.0f, 5.0f);
//    e1.print();
//}


//如果想要只能通过Log::print()调用函数，有两种方法
//#include<iostream>
//class Log
//{
////1>将构造函数设为private,类不能实例化
////private:
////    Log();
//
////2>删除默认构造函数，无法实例化
////    Log() = delete;
//
//public:
//    static void print()
//    {
//        std::cout << "hello" << std::endl;
//    }
//};
//
//int main()
//{
//    Log l;
//    l.print();
//}
//


//12.7
//1.析构函数：一种特殊的方法，当对象的生命周期结束时（比如超出作用域或被显式删除时），
//            析构函数会自动被调用，用于清理对象所占用的资源

//#include<iostream>
//class Entity
//{
//public:
//    int x, y;
//    //构造函数：
//    Entity()
//    {
//        x = 0;
//        y = 0;
//        std::cout << "Created Entity!" << std::endl;
//    }
//    //析构函数：
//    ~Entity()
//    {
//        std::cout << "Destroyed Entity!" << std::endl;
//    }
//    void print()
//    {
//        std::cout << x << "," << y << std::endl;
//    }
//};
//
//void function()
//{
//    Entity e;
//    e.print();
//}
//
//int main()
//{
//    function();
//    return 0;
//}

//总结：构造函数和析构函数可以省略，编译器会生成默认的版本
//      默认构造函数和析构函数适合简单的类，
//      但如果类需要动态内存管理或特定的初始化 / 清理操作，就需要显式定义它们


//2.继承：通过继承，一个类（派生类/子类）可以从另一个类（基类/父类）中
//        继承属性（成员变量）和行为（成员函数），实现代码复用和功能扩展 
//            --》减少代码重复

//#include<iostream>
//class Entity
//{
//public:
//    float x, y;
//    void move(float xa, float ya)
//    {
//        x += xa;
//        y += ya;
//    }
//};
//
////继承：
//class Player :public Entity    //******
//{
//public:
//    const char* name;
//    void printname()
//    {
//        std::cout << name << std::endl;
//    }
//};
//
//int main()
//{
//    Player player;
//    player.x = 0.0f;
//    player.name = "lyl";
//    player.printname();
//    return 0;
//}


//3.虚函数：（virtual）
// 允许派生类重写基类中的虚函数

//#include<iostream>
//#include<string>  //定义了std::string
//
//using namespace std;    //是一条命名空间声明语句，
//                        //它的作用是将【标准库】中的所有成员（如函数、类、变量等）引入到当前作用域中
//                        //这样在使用标准库的成员时就可以省略前缀 std::
//class Entity
//{
//public:
//    virtual std::string GetName()       //std::string是标准库（std 命名空间）提供的一个【类】，
//                                //用于表示和操作【字符串】
//    {
//        return "Entity";
//    }
//};
//
//class Player :public Entity
//{
//private:
//    std::string m_name;
//public:
//    Player(const std::string& name) :m_name(name) 
//    {
//        ;
//    }
//    virtual std::string GetName() override  //当子类定义和基类同名的函数时，基类的函数被隐藏，如果使用虚函数，则被重写
//    {                                       //override关键字：表示函数被重写，并且会规范代码
//        return m_name;
//    }
//};
//
//void print(Entity* e)
//{
//    std::cout << e->GetName() << std::endl;
//}
//int main()
//{
//    Entity* e = new Entity();  //加括号明确表示调用默认构造函数
//    //std::cout << e->GetName() << std::endl;   //打印Entity
//    print(e);   //打印Entity
//
//    Player* p = new Player("lyl");
//    //std::cout << p->GetName() << std::endl;   //打印lyl
//    print(p);    //打印Entity  -->解决方法：使用【虚函数 】
//
//    delete e;
//    delete p;
//    return 0;
//}


//12.8
//1.纯虚函数（接口）：
    //1>纯虚函数:是一个没有函数体的虚函数，
    //   --》定义形式为：virtual void functionName() = 0;
    //包含纯虚函数的类称为【抽象类】，抽象类不能直接实例化,必须被子类重写
    // 
    //2>接口:是一种特殊的抽象类，其中：所有成员函数都是纯虚函数。

//#include<iostream>
//#include<string>
//class printable
//{
//public:
//    virtual std::string GetName() = 0;  //纯虚函数
//};
//
//class Entity:public printable
//{
//public:
//    virtual std::string GetName() override
//    {
//        return "Entity";
//    }
//};
//
//class Player :public Entity
//{
//private:
//    std::string m_name;
//public:
//    Player(const char* name) :m_name(name) {}
//    virtual std::string GetName()  override
//    {
//        return m_name;
//    }
//};
//void print(printable* p)
//{
//    std::cout << p->GetName() << std::endl;
//}
//
//int main()
//{
//    Entity* e = new Entity();
//    print(e);
//    Player* p = new Player("lyl");
//    print(p);
//}


//2.可见性:public,protected,private
//1>public:类本身,子类,其他函数(作用域)中都可以调用
//2>protected:类本身和子类可以调用,其他函数(作用域)中不可以调用
//3>private:只有类本身可以调用(特殊:友元),子类和其他函数(作用域)中不可以调用
//
//#include<iostream>
//class Entity
//{
//protected:
//    int x;
//    void print(){}
//public:
//    Entity()
//    {
//        x = 0;
//        print();
//    }
//};
//class Player:public Entity
//{
//public:
//    Player()
//    {
//        x = 2;
//        print();
//    }
//};
//int main()
//{
//    Entity e;
//    e.x = 2;
//    e.print();
//    return 0;
//}


//3.字符串:std::string  类
//#include<iostream>
//#include<string>
//int main()
//{
//    std::string ch = "liaoyilin";
//    //追加字符串(strcat)
//    //std::string ch = "liaoyilin" + "hahah";  //语法错误
//    ch += "hahah";
//    //std::string ch = std::string("liaoyilin") + "hahah";
//    std::cout << ch << std::endl;
//
//    //求字符串长度.size()(strlen)
//    std::cout << ch.size() << std::endl;
//
//    //查找字符串
//    bool contains = ch.find("lin") != std::string::npos;  
//    int i = ch.find("lin");
//    std::cout << i << std::endl;
//    //如果子字符串存在，则返回其起始位置的索引；如果不存在，则返回 std::string::npos
//    //std::string::npos 是一个常量，表示“未找到”,它的值通常是一个大整数（实现依赖）
//}


//4.字符串字面量(字符串常量):
//****字符串字面量（例如"chnero"）被认为是一个 字符数组，而不是 std::string

//char* p = "hello";  p是一个指针，直接指向常量区，修改p[0]就是修改常量区的内容，这是不允许的。
//char p[] = "hello"; // 编译器在栈上创建一个字符串p，把"hello"从常量区复制到p，修改p[0]就相当于修改数组元素一样，是可以的。

//#include<iostream>
//int main()
//{
//    using namespace std::string_literals;
//    //可以将 "s" 后缀附加到字符串文字以直接创建 std::string 对象,"example"默认为const char* 类型
//    std::string ch = "hello"s + " world" + "!!";
//    //R:原始字符串文字的使用，()内允许您表示字符串，而无需转义换行符 ( \n ) 或引号等特殊字符
//    const char* example = R"(line1
//line2
//line3)";
//    std::cout << example << std::endl;
//    std::cout << ch << std::endl;
//}


//12.10
//1.const:(在类中)
//在成员函数后加上 const 关键字，表示该函数是一个常成员函数
//常成员函数的作用是保证该函数不会修改对象的成员变量（除非是被 mutable 修饰的成员变量）
//常成员函数只能调用常成员函数
//常变量只能调用常成员函数
//#include<iostream>
//class Entity
//{
//private:
//    int x;
//    mutable int y;  //mutable 修饰的成员可以被常成员函数修改
//public:
//    int Getx() const
//    {
//        y = 2;
//        return x;
//    }
//};
//void print(const Entity& e) //有const修饰：只能调用常成员函数
//{
//    std::cout << e.Getx() << std::endl;
//}
//
//int main()
//{
//    Entity e;
//    print(e);
//    return 0;
//}


//2.mutable:
//1>与const组合使用
//2>与lambda组合使用：auto f =[]()  （一次性函数）
//#include<iostream>
//int main()
//{
//    int x = 8;
//    auto f = [=]() mutable  //=对所有变量进行传值传递，&对所有变量进行传址传递
//                            //&x 对x引用传递，x 对x传值传递
//                            //传值传递时不能直接修改传递的变量，
//                            //加上mutable可以修改，但变量原本的值不变
//        {
//            /*int y = x;
//            y++;
//            std::cout << y << std::endl;*/
//            x++;
//            std::cout << x << std::endl;
//        };
//    f();
//    return 0;
//}


//2025.2.18
//1.成员初始化列表：
//成员初始化列表：是 C++ 构造函数的一种特殊语法，用于在构造函数体执行之前初始化类的成员变量
//它通过在构造函数的参数列表后使用冒号（ : ）和括号（()）来实现，
//成员1（值1），成员2（值2）... 必须按照变量的顺序一一赋值
//对于常量成员（const）和引用型成员（&）必须使用成员初始化列表


//1>初始化成员的不同方法：
//#include<iostream>
//#include<string>
//
//class Entity
//{
//public:
//    std::string m_name;
//    int height;
//
//    /*Entity()
//    {
//        m_name = "Unknown";
//    }*/
//    Entity() : m_name("Unknown"), height(158)  //有顺序（虽然VS下好像不影响）
//    {
//        ;//使构造函数的层次鲜明，便于阅读
//    }
//
//    std::string GetName()
//    {
//        return m_name;
//    }
//};
//
//int main()
//{
//    Entity e;
//    std::cout << e.GetName() << std::endl;
//    return 0;
//}


//2>优化性能：只初始化一次--》建议到处都用成员初始化列表
//#include<iostream>
//#include<string>
//
//class Example
//{
//public:
//    Example()
//    {
//        std::cout << "Created the Entity" << std::endl;
//    }
//    Example(int x)
//    {
//        std::cout << "Created the Entity with " << x << std::endl;
//    }
//};
//
//class Entity
//{
//public:
//    std::string m_name;
//    Example example;
//
//    /*Entity() 
//    {
//        m_name = "Unknown";
//        example = Example(8);
//    }*/
//    Entity()
//        :m_name("Unknown"), example(Example(8)) { }
//};
//
//int main()
//{
//    Entity e;
//    return 0;
//}


//2.19
//1.三元运算符：（嵌套）
//#include<iostream>
//int main()
//{
//    int level = 9;
//    int speed;
//    speed = level > 5 ? level > 10 ? 15 : 10 : 5;
//    //speed = level > 10 ?/*(*/ level > 5 ? 15 : 10/*)*/ : 5;
//    std::cout << speed << std::endl;
//    return 0;
//}


//2.创建并初始化c++对象：
//1>在栈上：
//#include<iostream>
//#include<string>
//using string = std::string;
//class Entity
//{
//public:
//    string m_name;
//
//    Entity(const string& name)
//    {
//        m_name = name;
//    }
//
//    const string& GetName() const
//    {
//        return m_name;
//    }
//};
//int main()
//{
//    Entity e("lyl");
//    std::cout << e.GetName() << std::endl;
//    return 0;
//}

//2>在堆上（对象占内存大，需要显式控制对象生命周期）：
//#include<iostream>
//#include<string>
//using string = std::string;
//class Entity
//{
//public:
//    string m_name;
//
//    Entity(const string& name)
//    {
//        m_name = name;
//    }
//
//    const string& GetName() const
//    {
//        return m_name;
//    }
//};
//int main()
//{
//    Entity* e = new Entity("lyl");
//    std::cout << e->GetName() << std::endl;
//    delete e;
//    return 0;
//}


//2.20
//1.new关键字：
//#include<iostream>
//class Entity
//{
//public:
//    std::string m_name;
//
//    Entity(const std::string& name)
//    {
//        m_name = name;
//    }
//
//    const std::string& GetName() const
//    {
//        return m_name;
//    }
//};
//int main()
//{
//    Entity* e = new Entity("lyl");
//    //相当于：Entity* e=(Entity*)malloc(sizeof(Entity)) + 调用构造函数
//    
//    int* a = new int;
//    int* b = new int[100];
//
//    delete e;
//    delete a;
//    delete[] b;  //特定形式
//    return 0;
//}


//2.c++的隐式转换（构造函数）和explicit关键字：
//c++允许编译器对代码进行【一次】隐式转换
//explicit用于修饰构造函数，表明禁用隐式转换

//#include<iostream>
//class Entity
//{
//public:
//    std::string m_name;
//    int m_age;
//
//    explicit Entity(const std::string& name):m_name(name),m_age(-1){}
//
//    explicit Entity(int age) :m_name("Unknown"), m_age(age){}
//
//};
//
////非常量引用：传入的必须是左值（可修改）
////常量引用（const）：传入的可以是左，右值（不可修改） -->代表引用的值不能更改
//void print(const Entity& Entity)
//{
//    ;
//}
//
//int main()
//{
//    Entity a("lyl"); //一次隐式转换：转换为std::string
//    Entity a = Entity("lyl");
//    //隐式转换：
//    Entity a = "lyl";  //两次隐式转换（不允许）：一次转换为std::string,一次转换为Entity
//    print(Entity("lyl"));
//
//    Entity b(20);
//    Entity b = Entity(20);
//    //隐式转换：
//    Entity b = 20;  //一次隐式转换：转换为Entity
//    print(20);
//    return 0;
//}


//3.运算符及其重载：
//运算符的重载其实是一个函数

//1>+/*的重载：简化代码，易于理解
//#include<iostream>
//struct Vector
//{
//    float x, y;
//
//    Vector(float x, float y):x(x),y(y){}
//
//    Vector add(const Vector& other) const
//    {
//        return Vector(x + other.x, y + other.y);
//    }
//
//    //成员函数重载：
//    //左侧操作数是调用该函数的对象，而右侧操作数是函数的参数
//    Vector operator+(const Vector& other) const
//    {
//        return add(other);
//    }
//
//    Vector mutiple(const Vector& other) const
//    {
//        return Vector(x * other.x, y * other.y);
//    }
//
//    Vector operator*(const Vector& other) const
//    {
//        return mutiple(other);
//    }
//};
//
//int main()
//{
//    Vector position = Vector(1.0f, 1.0f);
//    Vector speed = Vector(4.0f, 4.0f);
//    Vector powerup = Vector(1.1f, 1.1f);
//
//    Vector result = position.add(speed.mutiple(powerup));
//    Vector result = position + speed * powerup; //运算符重载后优先级保持不变
//
//    return 0;
//}

//2><<的重载：
//默认情况下，std::ostream(如：std::cout)只能输出基本类型
//如果想要自定义的类能直接输出，就需要重载<<

//#include<iostream>
//
//class Entity
//{
//public:
//    int x;
//    int y;
//
//    Entity(int x,int y):x(x),y(y){}
//
//};
//
////非成员函数重载：
////两个操作数都作为参数
//std::ostream& operator<<(std::ostream& stream, Entity e)
//{
//    stream << "(" << e.x << "," << e.y << ")";
//    return stream;
//}
//
//int main()
//{
//    Entity e(2, 3);
//    std::cout << e << std::endl;
//    return 0;
//}


//3>==的重载：判断自定义类的对象是否相等
//#include<iostream>
//
//class Entity
//{
//public:
//    int x;
//    int y;
//
//    Entity(int x, int y) :x(x), y(y) {}
//
//    bool operator==(const Entity& other) const
//    {
//        return x == other.x && y == other.y;
//    }
//
//    bool operator!=(const Entity& other) const
//    {
//        return !(*this == other);
//    }
//};
//
//int main()
//{
//    Entity e1(2, 3);
//    Entity e2(2, 4);
//    if (e1 == e2)
//    {
//        std::cout << "==" << std::endl;
//    }
//    return 0;
//}



//4.this关键字：
//this是一个指向当前对象实例的指针

//#include<iostream>
//void PrintEntity(Entity* e);
//
//class Entity
//{
//public:
//    int x;
//    int y;
//
//    Entity(int x, int y)
//    {
//        //x = x;
//        //变量名相同，无法给x,y赋值
//        this->x = x;
//        this->y = y;
//
//        //在类中调用类外的函数，且以类为参数
//        PrintEntity(this);
//    }
//};
//
//void PrintEntity(Entity* e)
//{
//    //print
//}
//
//int main()
//{
//    Entity e(2, 3);
//    return 0;
//}


//2.21
//1.栈作用域生存期：
//#include<iostream>
//
//class Entity
//{
//public:
//    Entity()
//    {
//        std::cout << "Created the Entity!" << std::endl;
//    }
//    ~Entity()
//    {
//        std::cout << "Destroyed the Entity!" << std::endl;
//    }
//};
//
////作用域指针（unique_ptr）
//class ScopedPtr
//{
//private:
//    Entity* m_ptr;
//public:
//    ScopedPtr(Entity* ptr):m_ptr(ptr){}
//    ~ScopedPtr()
//    {
//        delete m_ptr;
//    }
//};
//
//int main()
//{
//    {
//        ScopedPtr e = new Entity;  //隐式转换
//        //Entity* e = new Entity;
//    }
//    return 0;
//}


//2.22
//1.智能指针：自动化管理内存（自动化实现new,delete）
//     ->头文件：#include<memory>

//1>unique_ptr:
//作用域指针，出了作用域自动清除内存
//独占所有权的智能指针，它保证同一时间内只有一个unique_ptr可以管理一个对象
//它不能被复制，但可以被移动

//#include<iostream>
//#include<memory>
//
//class Entity
//{
//public:
//    Entity()
//    {
//        std::cout << "Created the Entity!" << std::endl;
//    }
//    ~Entity()
//    {
//        std::cout << "Destroyed the Entity!" << std::endl;
//    }
//};
//
//int main()
//{
//    {
//        //std::unique_ptr<Entity> e(new Entity());
//        std::unique_ptr<Entity> e = std::make_unique<Entity>();
//        //转移：
//        std::unique_ptr<Entity> e1 = std::move(e);
//    }
//    //动态内存分配
//    std::unique_ptr<int> a = std::make_unique<int>(30);
//    std::cout << *a << std::endl;
//    return 0;
//}

//2>shared_ptr:
//共享所有权的智能指针,允许多个shared_ptr实例共享同一个对象
//它通过引用计数来管理对象的生命周期
//有几个指针引用计数就为几，当引用计数为0时，内存被清除

//#include<iostream>
//#include<memory>
//
//class Entity
//{
//public:
//    Entity()
//    {
//        std::cout << "Created the Entity!" << std::endl;
//    }
//    ~Entity()
//    {
//        std::cout << "Destroyed the Entity!" << std::endl;
//    }
//};
//
//int main()
//{
//    {
//        std::shared_ptr<Entity> e0;
//        {
//            std::shared_ptr<Entity> e1 = std::make_shared<Entity>();
//            e0 = e1;
//        }
//    }
//
//    return 0;
//}

//3>weak_ptr:
//弱引用指针，它允许一个对象在不增加引用计数的情况下被访问
//它通常用于打破shared_ptr之间的循环引用

//#include<iostream>
//#include<memory>
//
//class Entity
//{
//public:
//    Entity()
//    {
//        std::cout << "Created the Entity!" << std::endl;
//    }
//    ~Entity()
//    {
//        std::cout << "Destroyed the Entity!" << std::endl;
//    }
//};
//
//int main()
//{
//    {
//        std::weak_ptr<Entity> e0;
//        {
//            std::shared_ptr<Entity> e1 = std::make_shared<Entity>();
//            e0 = e1;
//        }
//        //检查对象是否存在：
//        std::cout << e0.lock() << std::endl;
//    }
//    return 0;
//}



//2.22
//1.复制与拷贝构造函数：
//#include<iostream>
//#include<string>
//
//class String
//{
//private:
//    char* m_buffer;
//    unsigned int m_size;
//public:
//    String(const char* string)
//    {
//        m_size = strlen(string);
//        m_buffer = new char[m_size + 1];
//        memcpy(m_buffer, string, m_size);
//        m_buffer[m_size] = '\0';
//    }
//    //拷贝构造函数：
//    //拷贝构造函数是一种构造函数，它的参数是一个同类型的对象的引用（通常是const引用）
//    //它的作用是创建一个新对象，该对象是另一个对象的副本
//    //它在类对象被拷贝时调用
//
//    //1>默认拷贝构造函数：-->浅拷贝
//    //拷贝指针变量时，两个对象指向同一个内存块
//
//    /*String(const String& other)
//    {
//        m_buffer = other.m_buffer;
//        m_size = other.m_size;
//    }*/
//
//    //2>自定义拷贝构造函数：-->深拷贝
//    //拷贝指针变量时，两个对象指向不同内存块
//
//    String(const String& other)/* = delete;*/  //删除拷贝构造函数：不能拷贝类对象
//    {
//        std::cout << "Coped the String!" << std::endl;
//        m_size = other.m_size;
//        m_buffer = new char[m_size + 1];
//        memcpy(m_buffer, other.m_buffer, m_size + 1);
//    }
//
//    ~String()
//    {
//        //不能重复释放-->导致未定义行为
//        //浅拷贝（包含指针变量）时，易出现重复释放
//        delete[] m_buffer;
//    }
//    //友元函数：
//    //它不是类的成员函数，但可以访问类的私有（private）和保护（protected）成员
//    //格式：friend 返回类型 函数名(参数列表);
//    //定义可以写在类外（通常），也可以写在类内
//    //友元函数通常用于实现那些需要直接访问类内部数据的非成员函数，或者用于重载运算符等场景
//    friend std::ostream& operator<< (std::ostream& stream, const String& string);
//
//    char& operator[](const int& n)
//    {
//        return m_buffer[n];
//    }
//};
//
//std::ostream& operator<< (std::ostream& stream, const String& string)
//{
//    stream << string.m_buffer;
//    return stream;
//}
//
////如果String不加&，每次调用PrintString都会复制一次类对象（形参是实参的一份拷贝）
////这里出现过报错：想要使用重载运算符，参数类型必须一样
////一开始<<的函数参数无const,但PrintString的参数有const）
//void PrintString(const String& string)
//{
//    std::cout << string << std::endl;
//}
//
//int main()
//{
//    String string = "cherno";
//    String second = string; 
//
//    second[2] = 'a';
//
//    PrintString(string);
//    PrintString(second);
//
//    std::cin.get();
//    return 0;
//}  //浅拷贝时，作用域结束，string,second释放，char*指向的空间被释放两次-->程序崩溃
//
////总结：总是使用const & 传递  -->避免不必要的复制，浪费性能



//2.箭头操作符(->):
//1>
//#include<iostream>
//#include<string>
//
//class Entity
//{
//public:
//    int x;
//    void Print() const
//    {
//        std::cout << "hello!" << std::endl;
//    }
//};
//
//class ScopedPtr
//{
//public:
//    Entity* entity;
//    ScopedPtr(Entity* e) :entity(e){}
//    ~ScopedPtr()
//    {
//        delete entity;
//    }
//
//    const Entity* operator->() const 
//    {
//        return entity;
//    }
//};
//
//int main()
//{
//    const ScopedPtr ptr = new Entity;
//    //ptr.entity->Print();
//    ptr->Print();
//
//    std::cin.get();
//    return 0;
//}


//2>计算偏移量：
//#include<iostream>
//struct Vector3
//{
//    float x, y, z;  //偏移量：0，4，8
//};
//
//int main()
//{
//    int setoff = (int)&((Vector3*)0)->y;
//    //setoff = (int)(((Vector3*)0) + 1);
//    std::cout << setoff << std::endl;
//    return 0;
//}


//2.24
//1.动态数组（std::vector）
//#include<iostream>
//#include<vector>  //头文件
//
//class Vertex
//{
//public:
//    int x, y, z;
//};
//
//std::ostream& operator<< (std::ostream& stream, Vertex& v)
//{
//    stream << v.x << ',' << v.y << ',' << v.z;
//    return stream;
//}
//
//int main()
//{
//    std::vector<Vertex> vertices;
//    //push_back()添加对象
//    vertices.push_back({ 1,2,3 });
//    vertices.push_back({ 4,5,6 });
//    
//    //size()获取数组大小
//    for (int i = 0; i < vertices.size(); i++)
//    {
//        std::cout << vertices[i] << std::endl;
//    }
//
//    //删除元素
//    //vertices.clear();  //全部删除
//    vertices.erase(vertices.begin() + 1);  //删除某个元素
//
//    //这是一个范围-based for循环，是 C++11 引入的一种简化遍历容器的方式
//    //它的作用是遍历 vertices 中的每一个元素，并将每个元素赋值给变量 v，然后在循环体中处理 v
//    //这里 v 是 Vertex 的一个副本，每次迭代都会发生一次拷贝，为了避免拷贝，可以使用引用
//    //格式：类型 变量名：范围表达式
//    for (Vertex& v : vertices)
//    {
//        std::cout << v << std::endl;
//    }
//
//
//    std::cin.get();
//    return 0;
//}


//2.动态数组的优化：
//#include<iostream>
//#include<vector>
//
//class Vextex
//{
//public:
//    float x, y, z;
//
//    Vextex(float x, float y, float z) :x(x), y(y), z(z) {}
//    Vextex(const Vextex& other) :x(other.x), y(other.y), z(other.z)
//    {
//        std::cout << "Copied the Vextex" << std::endl;
//    }
//};
//
//int main()
//{
//    //一共复制了六次
//    //1>每次在main函数中创建Vextex对象，然后复制到vector中
//    //2>vector的初始容量为1，不够时会扩容（容量+1）
//    //  扩容是把原来内存中的内容复制到新内存中，并删除原来的内存，原来有几个元素就要复制几次
//    //std::vector<Vextex> vextices;
//    //vextices.push_back(Vextex(1, 2, 3));  //复制1次
//    //vextices.push_back(Vextex(4, 5, 6));  //复制2次
//    //vextices.push_back(Vextex(7, 8, 9));  //复制3次
//
//
//    //优化：复制0次
//    std::vector<Vextex> vextices;
//    //提前设置好内存：
//    vextices.reserve(3);
//    //使用emplace_back():
//    //1>push_back() 是一个成员函数，用于将一个【已存在的对象】添加到容器的末尾
//    //它接受一个完整的对象作为参数
//    //首先，它会创建一个临时对象（通常是通过拷贝或移动构造函数）
//    //然后，将这个临时对象拷贝或移动到容器的末尾
//    //最后，临时对象被销毁
//    // 
//    //2>emplace_back() 是C++11引入的成员函数，它的目标是在容器的末尾直接构造对象
//    //从而避免不必要的临时对象创建和拷贝 / 移动操作
//    //它接受构造函数的参数，并直接在容器分配的内存位置上构造对象。
//    vextices.emplace_back(1, 2, 3); 
//    vextices.emplace_back(4, 5, 6);  
//    vextices.emplace_back(7, 8, 9);  
//    std::cin.get();
//    return 0;
//}



//2.25（未完成）
//1.使用库（静态链接）：


//2.使用动态库：


//3.创建和使用库：



//2.26
//1.处理多返回值：
//  1>参数使用引用传递/指针：-->弊端：需要提前定义好变量
//  2>使用数组（std::array/std::vector）：-->弊端：数据类型必须一致

//  3>tuple元组/pair： -->弊端：使用返回值时容易混淆（没有变量名提示）-->结构化绑定
//#include<iostream>
//#include<tuple>  //包含tuple的定义
//#include<utility>  //包含pair的定义
//#include<iomanip> //包含fixed和setprecision


//tuple可以包含多个不同类型的数据
//std::tuple<int,double> Square(int a, double b)
//{
//    int x = a * a;
//    double y = b * b;
//    return std::make_tuple(x, y);
//}
//
//int main()
//{
//    std::tuple<int, double> result = Square(2, 4.0);
//    std::cout << std::fixed << std::setprecision(4);
//    //访问tuple中的元素：
//    std::cout << std::get<0>(result) << ',' << std::get<1>(result) << std::endl;
//    std::cin.get();
//    return 0;
//}


//pair只可以包含两个不同类型的数据
//std::pair<int, double> Square(int a, double b)
//{
//    int x = a * a;
//    double y = b * b;
//    return std::make_pair(x, y);
//}
//
//int main()
//{
//    std::pair<int, double> result = Square(2, 4.0);
//    std::cout << std::fixed << std::setprecision(4);
//    //访问pair中的元素：
//    //std::cout << std::get<0>(result) << ',' << std::get<1>(result) << std::endl;
//    std::cout << result.first << ',' << result.second << std::endl;
//    std::cin.get();
//    return 0;
//}

//  4>使用结构体：
//#include<iostream>
//#include<iomanip>
//struct math
//{
//    int x;
//    double y;
//};
// 
//struct math Square(int a, double b)
//{
//    int x = a * a;
//    double y = b * b;
//    struct math m = { x,y };
//    return m;
//}
//
//int main()
//{
//    struct math result = Square(2, 4.0);
//    std::cout << std::fixed << std::setprecision(4);
//    std::cout << result.x << ',' << result.y << std::endl;
//    std::cin.get();
//    return 0;
//}


//  补充：结构化绑定（C++17引入）：可以对tuple,pair,数组和自定义结构体使用
//#include<iostream>
//#include<tuple>
//#include<iomanip>
//std::tuple<int,double> Square(int a, double b)
//{
//    int x = a * a;
//    double y = b * b;
//    return std::make_tuple(x, y);
//}
//
//int main()
//{
//    std::tuple<int, double> result = Square(2, 4.0);
//    std::cout << std::fixed << std::setprecision(4);
//    //***结构化绑定：
//    auto [x, y] = result;
//    //访问tuple中的元素：
//    std::cout << x << ',' << y << std::endl;
//    std::cin.get();
//    return 0;
//}



//2.28
//1.模板（template）:（元编程）
//实际上并不存在，只有当它被调用时才创建

//#include<iostream>
//1>减少重载类似的代码：
//template<typename T>
//void Print(T value)
//{
//    std::cout << value << std::endl;
//}
//int main()
//{
//    //隐式：
//    Print(5);
//    //显式：
//    Print<int>(5);
//
//    Print(5.5f);
//    Print("lyl");
//    std::cin.get();
//    return 0;
//}


//2>
//template<typename T, int N>
//class Array
//{
//private:
//    T array[N];
//public:
//    void GetSize()
//    {
//        std::cout << N << std::endl;
//    }
//};
//int main()
//{
//    Array<int, 5> array;
//    Array<std::string, 50> string;
//    std::cin.get();
//    return 0;
//}


//2.宏：
//实际应用中，想要一些代码只在Debug模式下运行，而在Release模式下不运行
//在项目-属性-c/c++ -预处理器-预处理器定义中定义Debug/Debug=1 
//#include<iostream>

//#ifdef Debug
//#define Log(x) std::cout<<x<<std::endl
//#else
//#define Log(x)
//#endif

//#define Debug 0

//#if Debug==1
//#define Log(x) std::cout<<x<<std::endl
//#else
//#define Log(x)
//#endif
//
//int main()
//{
//    Log("lyl");
//    return 0;
//}

//宏必须写在一行，可以使用转义字符 \ 换行
//#include<iostream>
//#define Main int main()\
//{\
//     std::cin.get();\
//     return 0;\
//}
//Main



//3.auto关键字：用于自动推导变量的类型-->用于变量类型太长的情况
//1>
//#include<iostream>
//#include<vector>
//int main()
//{
//    std::vector<std::string> strings;
//    strings.push_back("Apple");
//    strings.push_back("Orange");
//    //迭代器(iterator)：类似指针的作用和用法
//    //begin()返回一个迭代器，指向第一个元素，end()返回一个迭代器，指向最后一个元素的下一个位置
//
//    /*for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
//    {
//        std::cout << *it << std::endl;
//    }*/
//    for (auto it = strings.begin(); it != strings.end(); it++)
//    {
//        std::cout << *it << std::endl;
//    }
//    std::cin.get();
//    return 0;
//}


//2>
//#include<iostream>
//#include<unordered_map>
//#include<vector>
////std::unordered_map<,> 键值对【集合】->类似数组
////用于存储键值对,基于哈希表实现
////通过键可以快速找到对应的值
//class Device{};
//class DeviceManager
//{
//private:
//    std::unordered_map<std::string, std::vector<Device*>> m_Devices;
//public:
//    const std::unordered_map<std::string, std::vector<Device*>>& GetDevice() const
//    {
//        return m_Devices;
//    }
//};
//int main()
//{
//    DeviceManager dev;
//    //const std::unordered_map<std::string, std::vector<Device*>>& device = dev.GetDevice();
//    const auto& device = dev.GetDevice();
//    //auto默认会忽略引用的性质，直接推导出引用所指向的原始类型
//    //需要时要显式加上引用&
//    std::cin.get();
//    return 0;
//}


//3.1
//1.函数指针：返回值（* 函数指针名）（参数）
//#include<iostream>
//#include<vector>
//
//using namespace std;
//void PrintValue(int value)
//{
//    std::cout << value << std::endl;
//}
//
//void ForEach(std::vector<int> values, void(*fuc)(int))
//{
//    for (int value : values)
//        fuc(value);
//}
//
//int main()
//{
//    std::vector<int> values = { 1,2,3,4,5 };
//    ForEach(values, PrintValue);
//    std::cin.get();
//    return 0;
//}



//2.lamda函数：类似于匿名函数，便于随用随定义，不用到其他地方去定义个函数
//格式：[](){} 
//格式：[外层变量传入](参数变量传入) -> 返回类型 { 函数体 }; 
//(->返回变量可以不写，因为很容易从return推断)
//[](=表示对所有变量进行传值传递，&表示对所有变量进行传址传递）
//#include<iostream>
//#include<vector>
//#include<functional>  //std::function的头文件

//1>
//std::function 提供了一种统一的方式来调用不同的可调用对象
//void ForEach(std::vector<int> values, std::function<void(int)> fuc)
//{
//    for (int value : values)
//        fuc(value);
//}
//
//int main()
//{
//    std::vector<int> values = { 1,2,3,4,5 };
//    ForEach(values, [](int value) { std::cout << value << std::endl; });
//    //int a = 5;
//    //ForEach(values, [=](int value) mutable { a = 10; std::cout << value << a << std::endl; });
//    ////传值传递不能修改变量的值-->使用mutable解决
//    std::cin.get();
//    return 0;
//}

//2>
//#include<algorithm>  //std::find_if()的头文件

//std::find_if 是一个通用的查找算法，
//用于在容器（如 std::vector、std::list、std::array 等）中查找满足特定条件的【第一个】元素
//它接受一个范围（通过迭代器指定）和一个谓词，返回一个迭代器
//谓词一个接受单个参数的可调用对象，返回一个布尔值，如果返回 true，则表示当前元素满足条件

//int main()
//{
//    std::vector<int> values = { 1,2,3,4,5 };
//    auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; });
//    std::cout << *it << std::endl;
//    return 0;
//}



//3.2
//1.名称空间：避免命名冲突
//类本身也是一种命名空间，使用静态函数时要类名::
//注意：尽量不使用using namespace std; 可以对自己的库使用或在小范围的作用域内
//！！！！绝对不要在头文件中使用using namespace std; 头文件被包含时，会造成重大错误
//#include<iostream>
//#include<string>
//namespace Apple
//{
//    void print(std::string text)
//    {
//        std::cout << text << std::endl;
//    }
//}
//
//namespace Orange
//{
//    void print(const char* text)
//    {
//        std::string tmp = text;
//        std::reverse(tmp.begin(), tmp.end());
//        std::cout << tmp << std::endl;
//    }
//}
//using namespace Apple;
//using namespace Orange;
//
//int main()
//{
//    print("hello");  //"hello"本身是const char* 类型，调用Apple::print()时发生了隐式转换
//    std::cin.get();
//    return 0;
//}

//#include<iostream>
////命名空间的嵌套
//namespace Apple 
//{
//    namespace function 
//    {
//        void print(const char* text)
//        {
//            std::cout << text << std::endl;
//        }
//    }
//
//    void print_again()
//    {
//        ;
//    }
//}
//int main()
//{
//    //Apple::function::print("hello");
//    
//    //using namespace Apple;
//    //function::print("hello");
//
//    //using namespace Apple::function;
//    //print("hello");
//
//    //命名空间的赋值
//    //namespace a = Apple::function;
//    //a::print("hello");
//    std::cin.get();
//    return 0;
//}



//2.线程：允许同时进行多项任务
//#include<iostream>
//#include<thread>  //命名空间this_thread的头文件
//#include<chrono>

//std::literals::chrono_literals 提供了以下时间单位的字面量操作符：->编译器不支持？
//h：表示小时（std::chrono::hours）
//min：表示分钟（std::chrono::minutes）
//s：表示秒（std::chrono::seconds）

//using namespace std::literals::chrono_literals;
//
//static bool is_finished = false;
//
//void dowork()
//{
//    std::cout << "start the thread\n";
//    std::cout << "the id of thread: " << std::this_thread::get_id() << std::endl;
//    while (!is_finished)
//    {
//        std::cout << "working..." << std::endl;
//        std::this_thread::sleep_for(1s);
//    }
//}
//
//int main()
//{
//    std::thread worker(dowork);
//    std::cin.get();
//    is_finished = true;
//
//    //调用join的线程会阻塞，直到目标线程（worker）结束
//    worker.join();
//    std::cout << "finish the thread\n";
//    std::cout << "the id of the thread:" << std::this_thread::get_id() << std::endl;
//    std::cin.get();
//    return 0;
//}



//3.3
//1.计时：用来作为优化性能的指标

//1>
//#include<iostream>
//#include<chrono>
//#include<thread>
//int main()
//{
//    using namespace std::literals::chrono_literals;
//
//    //std::chrono::high_resolution_clock 是一种高精度时钟，通常用于测量时间间隔
//    //now() 函数返回当前时间点（time_point）
//    auto start = std::chrono::high_resolution_clock::now();
//    std::this_thread::sleep_for(1s);
//    auto end = std::chrono::high_resolution_clock::now();
//
//    std::chrono::duration <float> duration = end - start;
//    //duration本身带单位，count()取其数值部分
//    std::cout << duration.count() << "s" << std::endl;
//
//    std::cin.get();
//    return 0;
//}

//2>****利用生命周期：
//#include<iostream>
//#include<chrono>
//
//class Timer
//{
//public:
//    //std::chrono::time_point 是一个表示时间点的类模板
//    //它通常与某种时钟（如 std::chrono::steady_clock 或 std::chrono::high_resolution_clock）一起使用
//    //time_point 表示一个具体的时刻，例如“程序开始运行的时间”或“某个操作完成的时间”
//    std::chrono::time_point<std::chrono::steady_clock > start, end;
//
//    //std::chrono::duration 是一个表示时间间隔的类模板
//    //用于表示两个时间点之间的差值
//    std::chrono::duration <float> duration;
//
//    Timer()
//    {
//        start = std::chrono::high_resolution_clock::now();
//    }
//    ~Timer()
//    {
//        end = std::chrono::high_resolution_clock::now();
//        duration = end - start;
//        float ms = duration.count() * 1000.0f;
//        std::cout << "Time took " << ms << "ms" << std::endl;
//    }
//};
//
//void Function()
//{
//    Timer timer;
//
//    for (int i = 0; i < 100; i++)
//        //std::cout << "hello" << std::endl;
//        std::cout << "hello\n";   //速度更快
//}
//int main()
//{
//    Function();
//    std::cin.get();
//    return 0;
//}



//3.4
//1.多维数组：
//#include<iostream>
//int main()
//{
//    //一维数组：
//    int* arr = new int[5]();   //空的圆括号代表初始化为0
//    delete[] arr;
//
//    //二维数组：内存分散，性能低
//    int i, j;
//    int** a2d = new int* [5];
//    for (i = 0; i < 5; i++)
//        a2d[i] = new int[5];
//    
//    for (i = 0; i < 5; i++)
//    {
//        for (j = 0; j < 5; j++)
//        {
//            a2d[i][j] = 0;
//        }
//    }
//
//    for (i = 0; i < 5; i++)
//        delete[] a2d[i];
//    delete[] a2d;
//
//    //一维数组表示二维数组：内存集中
//    int* p = new int[5 * 5];
//    //访问
//    for (i = 0; i < 5; i++)
//    {
//        for (j = 0; j < 5; j++)
//        {
//            p[i * 5 + j] = 0;
//        }
//    }
//    delete[] p;
//    return 0;
//}


//实验：差得不太多
//#include<iostream>
//#include<chrono>
//class Timer
//{
//public:
//    std::chrono::time_point < std::chrono::high_resolution_clock  >start, end;
//    std::chrono::duration<float> duration;
//    Timer()
//    {
//        start = std::chrono::high_resolution_clock::now();
//    }
//    ~Timer()
//    {
//        end = std::chrono::high_resolution_clock::now();
//        duration = (end - start) * 10e3;
//        std::cout << duration.count() << "ms";
//    }
//};
//int main()
//{
//    Timer timer;
//    int i, j;
//    int** a2d = new int* [5];
//    for (i = 0; i < 5; i++)
//        a2d[i] = new int[5];
//    
//    for (i = 0; i < 5; i++)
//    {
//        for (j = 0; j < 5; j++)
//        {
//            a2d[i][j] = 0;
//        }
//    }
//
//    for (i = 0; i < 5; i++)
//        delete[] a2d[i];
//    delete[] a2d;
//
//    //int i, j;
//    //int* p = new int[5 * 5];
//    ////访问
//    //for (i = 0; i < 5; i++)
//    //{
//    //    for (j = 0; j < 5; j++)
//    //    {
//    //        p[i * 5 + j] = 0;
//    //    }
//    //}
//    //delete[] p;
//    return 0;
//}



//2.排序：std::sort(迭代器，迭代器，谓词)
//谓词：是一个函数或表达式，它接受一个或多个输入参数，并返回一个布尔值
//根据返回值，可以判断某个条件是否满足

//#include<iostream>
//#include<vector>
//#include<algorithm>  //std::sort的头文件
//
//int main()
//{
//    std::vector<int> arr = { 5,2,4,1,3 };
//    //std::sort(arr.begin(), arr.end());  //谓词为空时，默认升序排列（只对内置类型有效）
//
//    //谓词返回true时，a排在b前面；返回false时，b排在a前面
//    std::sort(arr.begin(), arr.end(), [](int a, int b)
//        {
//            //return a > b;  //降序
//
//            if (a == 1)
//                return false;
//            if (b == 1)
//                return true;
//            return a < b;
//        });
//    for (int value : arr)
//        std::cout << value << std::endl;
//    return 0;
//}

