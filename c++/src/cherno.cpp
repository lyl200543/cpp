//#include<iostream>
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	std::cin.get();
//}

//11.30
//1.���ã�& -->�����ں����������ݣ�ʹ���������Ķ�
// 
//  -->�ص�:
//1>����������ͨ����Ϊһ�����б����ṩ��һ�����֣�ֱ�Ӳ������þ͵�ͬ�ڲ���ԭ����
//2>ָ���ڴ��ַ������ָ��������ڴ��еĵ�ַ������ֵ����
//3>�����޸ģ�ͨ�������޸�����ʱ��ԭʼ������ͬ���仯
//4>����ʱ��Ҫ��ʼ������֮���޷�����ָ��
//5>���ò��Ǳ����������ڴ��д����ռ�

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

//2.�ࣺclass  -->ʹ�������׶�
//  ��C++����������̣�OOP���ĺ��ĸ���,�����û��Զ��������
//  ����������ɵı�����Ϊ����
// 
//  -->��Ļ������:
//
//   1>���ݳ�Ա����Ա��������
//      ���ڴ洢��������Ի�״̬
//      �����ǻ����������͡������ͻ�ָ��
// 
//   2>��Ա��������Ҳ����������
//      �������ݳ�Ա�ĺ���������������Ϊ
//      ������ͨ�����͹��캯�������������������Ա����
// 
//   3>����Ȩ�ޣ�
//      �������Ա�ķ��ʷ�Χ
//       �����ַ������η���
		//public: ���г�Ա��������Է��ʡ�
		//private: ˽�г�Ա�������ڲ����Է��ʣ�Ĭ�ϣ���
		//protected: �ܱ�����Ա�����༰����������Է��ʡ�

//#include<iostream>
//class player
//{
//public:  //Ĭ��Ϊprivate
//	int x, y;
//	int speed;
//
//	void move(int xa, int ya)  //����
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
// ��c++�У�struct��classֻ�пɼ��Ե�����struct�Ŀɼ���Ĭ��Ϊpublic,��class�Ŀɼ���Ĭ��Ϊprivate
//          ��ͨ������ֻ�����ɸ���Ա����ʱ��struct���漰������������ʱ��class
// 
//��c�У�stuctֻ�ܱ�ʾ����
//��c++�У�struct�ܰ����������������ܣ���class��ͬ )


//12.1
//1.���дһ��c++�ࣺ( log�� )
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


//2.�ؼ���static:(���α�������)

//1>����ͽṹ��֮��:
      //��ʾ�����������ڲ����ӵ�,��������һ��c++�ļ���ʹ��
      //��ͷ�ļ��а��� static �������ᵼ��ÿ������ͷ�ļ��ı��뵥Ԫ������һ�������ı���ʵ��
      
//����:ʵ��:<1>��:����ģ��,��ʵ���Ǿ���ʵ��,һ��������ж��ʵ��
         // <2>����:һ�������ڳ�������ʱ�����˴洢�ռ䲢�洢��ʵ��ֵ���ⱻ��Ϊ����ʵ��



//2>*****����ͽṹ��֮��***********:
     //static ���α���:��ʾ�������������࣬��������ĳ������
         //<1>�������ʵ������ͬһ�� x �� y �Ĵ洢�ռ�
         //<2>�����������󣬱��������ⶨ��ͳ�ʼ��

    //static ���κ���:��̬�������������κ����ʵ��������ֱ��ͨ����������
         // **ֻ�ܷ�����ľ�̬��Ա������ֱ�ӷ��ʷǾ�̬��Ա


//1.��static����:
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

//2. static ���α���
//#include<iostream>
//struct Entity
//{
//    static int x, y;  //ֻ������,û�ж���ͳ�ʼ��
//
//    void print()
//    {
//        std::cout << x << "," << y << std::endl;
//    }
//};
//
////****�����ⲿ���徲̬����ʱ����Ҫ��������������޶��� Entity::
////�����Ƕ���,û�г�ʼ��
//int Entity::x;
//int Entity::y;
//
//int main()
//{
//    /*Entity e;
//    e.x = 2;
//    e.y = 3;*/
//    Entity::x = 2;   //�����ǳ�ʼ��
//    Entity::y = 3;
//
//    /*Entity e1;
//    e1.x = 5;
//    e1.y = 8;*/
//    Entity::x = 5;
//    Entity::y = 8;
//
//    //���һ�����д��ھ�̬�����ͷǾ�̬������
//    //Ҫ���������÷Ǿ�̬�����������ȴ��������ʵ����Ȼ��ͨ����ʵ�����÷Ǿ�̬����
//    Entity e;
//    e.print();
//
//}

//3.static ���η���:
// 
//��̬�����޷�ֱ�ӷ��ʷǾ�̬��������Ϊ��̬����û��ʵ��������
//�����Ҫ�ھ�̬�����з��ʷǾ�̬����������ͨ����ʵ��������Ϊ�������ݸ���̬������ʵ��
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
//1.enum(ö�����ͣ�����������һ����ֵ���������ļ��ϣ�ʹ�������ڹ�����Ķ�
// 
//#include<iostream>
//enum example: unsigned char  //����ָ���ײ����ͣ����������ͼ��壬Ĭ����int�� -->��Լ�ռ䣬�����ض�����
//{
//    A,  //�������ʼ����Ĭ��ֵΪ0�������ε���
//    B,
//    C
//};
//
//int main()
//{
//    int value1 = A;
//    example value2 = A; //ʹ��enum���Ͷ������ʱ��ֻ�ܸ�enum�е�ֵ
//}

//��дlog�ࣺ
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
//	//�� C++ �У�enum ���ͣ�ö�٣���Ա����Ϊ��ľ�̬��Ա��
//	// ���������������ĳ������Ķ���,����ζ���������������ʵ���ж��ǹ����
//	// ��ˣ�����ö�ٳ�Աʱ��Ҫͨ��������Log::levelError��������ʵ������log.levelError��������
//
//	//���ǣ�ĳЩ����£�log.levelErrorҲ���ԣ�
//	//enum level ��һ����ͨ��ö�����ͣ�û��ʹ�� enum class��
//	// �� C++ �У���ͨ��ö�ٻ�����ĳ�Ա�����������������
//	// ��ˣ����������� Log �ڲ������� enum level��
//	// ��������� levelError��levelWarning �� levelInfo ������ĳ�Ա������
//	// 
//	//�������ǿ����ö�٣�enum class�������Ա�ᱻ�ϸ��޶���ö�ٵ��������ڣ�
//	// ����ͨ�����������ֱ�ӷ��ʣ�����ʹ�� Log::levelWarning��
//
//
//	log.Error("hello!");
//	log.Warn("hello!");
//	log.Info("hello!");
//	std::cin.get();
//}


//12.4
//1.���캯����
// һ�����е�����ķ�����ֻ���ڴ��������ʵ��ʱ�����У���Ҫ��;�ǳ�ʼ����
//������û����ʽ���幹�캯��ʱ�����������Զ�����һ��Ĭ�Ϲ��캯����ʹ�����ܹ���ʵ����
//�����ʽ��ɾ����= delete�����캯�������޷�ͨ��Ĭ�Ϲ���ʵ��������
//���캯�������ж��

//#include<iostream>
//#include<iomanip>  //std::fixed  -->���������������ʽ����Ϊ�̶���С�����ʽ
//                  //std::setprecision(2)����������ĸ���������Ϊ 2�������� 2 λС��         
//class Entity
//{
//public:
//    float X, Y;
//
//    //��ʽ���幹�캯������������������û�з���ֵ����
//    Entity()
//    {
//        X = 0.0f;
//        Y = 0.0f;
//    }
//
//    //�������أ��������������ͬ�����������ͣ�˳��������ͬ������ֵ���Ͳ������ֺ������أ�
//    Entity(float x, float y)
//    {
//        X = x;
//        Y = y;
//    }
//
//    void print()
//    {
//        std::cout << X << " " << Y << std::endl;  //std::coutĬ����int��ʽ���
//        //std::cout << std::fixed << std::setprecision(2) << X << " " << Y << std::endl;
//    }
//};
//int main()
//{
//    /*Entity e;
//    std::cout << e.X << std::endl;*/  //e.Xû�г�ʼ�����ᱨ��
//
//    //ʹ��Entity()���캯��
//    Entity e;
//    e.print();
//    //ʹ��Entity(float x, float y)���캯��
//    Entity e1(10.0f, 5.0f);
//    e1.print();
//}


//�����Ҫֻ��ͨ��Log::print()���ú����������ַ���
//#include<iostream>
//class Log
//{
////1>�����캯����Ϊprivate,�಻��ʵ����
////private:
////    Log();
//
////2>ɾ��Ĭ�Ϲ��캯�����޷�ʵ����
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
//1.����������һ������ķ�������������������ڽ���ʱ�����糬�����������ʽɾ��ʱ����
//            �����������Զ������ã��������������ռ�õ���Դ

//#include<iostream>
//class Entity
//{
//public:
//    int x, y;
//    //���캯����
//    Entity()
//    {
//        x = 0;
//        y = 0;
//        std::cout << "Created Entity!" << std::endl;
//    }
//    //����������
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

//�ܽ᣺���캯����������������ʡ�ԣ�������������Ĭ�ϵİ汾
//      Ĭ�Ϲ��캯�������������ʺϼ򵥵��࣬
//      ���������Ҫ��̬�ڴ������ض��ĳ�ʼ�� / �������������Ҫ��ʽ��������


//2.�̳У�ͨ���̳У�һ���ࣨ������/���ࣩ���Դ���һ���ࣨ����/���ࣩ��
//        �̳����ԣ���Ա����������Ϊ����Ա��������ʵ�ִ��븴�ú͹�����չ 
//            --�����ٴ����ظ�

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
////�̳У�
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


//3.�麯������virtual��
// ������������д�����е��麯��

//#include<iostream>
//#include<string>  //������std::string
//
//using namespace std;    //��һ�������ռ�������䣬
//                        //���������ǽ�����׼�⡿�е����г�Ա���纯�����ࡢ�����ȣ����뵽��ǰ��������
//                        //������ʹ�ñ�׼��ĳ�Աʱ�Ϳ���ʡ��ǰ׺ std::
//class Entity
//{
//public:
//    virtual std::string GetName()       //std::string�Ǳ�׼�⣨std �����ռ䣩�ṩ��һ�����ࡿ��
//                                //���ڱ�ʾ�Ͳ������ַ�����
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
//    virtual std::string GetName() override  //�����ඨ��ͻ���ͬ���ĺ���ʱ������ĺ��������أ����ʹ���麯��������д
//    {                                       //override�ؼ��֣���ʾ��������д�����һ�淶����
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
//    Entity* e = new Entity();  //��������ȷ��ʾ����Ĭ�Ϲ��캯��
//    //std::cout << e->GetName() << std::endl;   //��ӡEntity
//    print(e);   //��ӡEntity
//
//    Player* p = new Player("lyl");
//    //std::cout << p->GetName() << std::endl;   //��ӡlyl
//    print(p);    //��ӡEntity  -->���������ʹ�á��麯�� ��
//
//    delete e;
//    delete p;
//    return 0;
//}


//12.8
//1.���麯�����ӿڣ���
    //1>���麯��:��һ��û�к�������麯����
    //   --��������ʽΪ��virtual void functionName() = 0;
    //�������麯�������Ϊ�������ࡿ�������಻��ֱ��ʵ����,���뱻������д
    // 
    //2>�ӿ�:��һ������ĳ����࣬���У����г�Ա�������Ǵ��麯����

//#include<iostream>
//#include<string>
//class printable
//{
//public:
//    virtual std::string GetName() = 0;  //���麯��
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


//2.�ɼ���:public,protected,private
//1>public:�౾��,����,��������(������)�ж����Ե���
//2>protected:�౾���������Ե���,��������(������)�в����Ե���
//3>private:ֻ���౾����Ե���(����:��Ԫ),�������������(������)�в����Ե���
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


//3.�ַ���:std::string  ��
//#include<iostream>
//#include<string>
//int main()
//{
//    std::string ch = "liaoyilin";
//    //׷���ַ���(strcat)
//    //std::string ch = "liaoyilin" + "hahah";  //�﷨����
//    ch += "hahah";
//    //std::string ch = std::string("liaoyilin") + "hahah";
//    std::cout << ch << std::endl;
//
//    //���ַ�������.size()(strlen)
//    std::cout << ch.size() << std::endl;
//
//    //�����ַ���
//    bool contains = ch.find("lin") != std::string::npos;  
//    int i = ch.find("lin");
//    std::cout << i << std::endl;
//    //������ַ������ڣ��򷵻�����ʼλ�õ���������������ڣ��򷵻� std::string::npos
//    //std::string::npos ��һ����������ʾ��δ�ҵ���,����ֵͨ����һ����������ʵ��������
//}


//4.�ַ���������(�ַ�������):
//****�ַ���������������"chnero"������Ϊ��һ�� �ַ����飬������ std::string

//char* p = "hello";  p��һ��ָ�룬ֱ��ָ���������޸�p[0]�����޸ĳ����������ݣ����ǲ�����ġ�
//char p[] = "hello"; // ��������ջ�ϴ���һ���ַ���p����"hello"�ӳ��������Ƶ�p���޸�p[0]���൱���޸�����Ԫ��һ�����ǿ��Եġ�

//#include<iostream>
//int main()
//{
//    using namespace std::string_literals;
//    //���Խ� "s" ��׺���ӵ��ַ���������ֱ�Ӵ��� std::string ����,"example"Ĭ��Ϊconst char* ����
//    std::string ch = "hello"s + " world" + "!!";
//    //R:ԭʼ�ַ������ֵ�ʹ�ã�()����������ʾ�ַ�����������ת�廻�з� ( \n ) �����ŵ������ַ�
//    const char* example = R"(line1
//line2
//line3)";
//    std::cout << example << std::endl;
//    std::cout << ch << std::endl;
//}


//12.10
//1.const:(������)
//�ڳ�Ա��������� const �ؼ��֣���ʾ�ú�����һ������Ա����
//����Ա�����������Ǳ�֤�ú��������޸Ķ���ĳ�Ա�����������Ǳ� mutable ���εĳ�Ա������
//����Ա����ֻ�ܵ��ó���Ա����
//������ֻ�ܵ��ó���Ա����
//#include<iostream>
//class Entity
//{
//private:
//    int x;
//    mutable int y;  //mutable ���εĳ�Ա���Ա�����Ա�����޸�
//public:
//    int Getx() const
//    {
//        y = 2;
//        return x;
//    }
//};
//void print(const Entity& e) //��const���Σ�ֻ�ܵ��ó���Ա����
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
//1>��const���ʹ��
//2>��lambda���ʹ�ã�auto f =[]()  ��һ���Ժ�����
//#include<iostream>
//int main()
//{
//    int x = 8;
//    auto f = [=]() mutable  //=�����б������д�ֵ���ݣ�&�����б������д�ַ����
//                            //&x ��x���ô��ݣ�x ��x��ֵ����
//                            //��ֵ����ʱ����ֱ���޸Ĵ��ݵı�����
//                            //����mutable�����޸ģ�������ԭ����ֵ����
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
//1.��Ա��ʼ���б�
//��Ա��ʼ���б��� C++ ���캯����һ�������﷨�������ڹ��캯����ִ��֮ǰ��ʼ����ĳ�Ա����
//��ͨ���ڹ��캯���Ĳ����б��ʹ��ð�ţ� : �������ţ�()����ʵ�֣�
//��Ա1��ֵ1������Ա2��ֵ2��... ���밴�ձ�����˳��һһ��ֵ
//���ڳ�����Ա��const���������ͳ�Ա��&������ʹ�ó�Ա��ʼ���б�


//1>��ʼ����Ա�Ĳ�ͬ������
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
//    Entity() : m_name("Unknown"), height(158)  //��˳����ȻVS�º���Ӱ�죩
//    {
//        ;//ʹ���캯���Ĳ�������������Ķ�
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


//2>�Ż����ܣ�ֻ��ʼ��һ��--�����鵽�����ó�Ա��ʼ���б�
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
//1.��Ԫ���������Ƕ�ף�
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


//2.��������ʼ��c++����
//1>��ջ�ϣ�
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

//2>�ڶ��ϣ�����ռ�ڴ����Ҫ��ʽ���ƶ����������ڣ���
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
//1.new�ؼ��֣�
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
//    //�൱�ڣ�Entity* e=(Entity*)malloc(sizeof(Entity)) + ���ù��캯��
//    
//    int* a = new int;
//    int* b = new int[100];
//
//    delete e;
//    delete a;
//    delete[] b;  //�ض���ʽ
//    return 0;
//}


//2.c++����ʽת�������캯������explicit�ؼ��֣�
//c++����������Դ�����С�һ�Ρ���ʽת��
//explicit�������ι��캯��������������ʽת��

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
////�ǳ������ã�����ı�������ֵ�����޸ģ�
////�������ã�const��������Ŀ���������ֵ�������޸ģ� -->�������õ�ֵ���ܸ���
//void print(const Entity& Entity)
//{
//    ;
//}
//
//int main()
//{
//    Entity a("lyl"); //һ����ʽת����ת��Ϊstd::string
//    Entity a = Entity("lyl");
//    //��ʽת����
//    Entity a = "lyl";  //������ʽת������������һ��ת��Ϊstd::string,һ��ת��ΪEntity
//    print(Entity("lyl"));
//
//    Entity b(20);
//    Entity b = Entity(20);
//    //��ʽת����
//    Entity b = 20;  //һ����ʽת����ת��ΪEntity
//    print(20);
//    return 0;
//}


//3.������������أ�
//�������������ʵ��һ������

//1>+/*�����أ��򻯴��룬�������
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
//    //��Ա�������أ�
//    //���������ǵ��øú����Ķ��󣬶��Ҳ�������Ǻ����Ĳ���
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
//    Vector result = position + speed * powerup; //��������غ����ȼ����ֲ���
//
//    return 0;
//}

//2><<�����أ�
//Ĭ������£�std::ostream(�磺std::cout)ֻ�������������
//�����Ҫ�Զ��������ֱ�����������Ҫ����<<

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
////�ǳ�Ա�������أ�
////��������������Ϊ����
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


//3>==�����أ��ж��Զ�����Ķ����Ƿ����
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



//4.this�ؼ��֣�
//this��һ��ָ��ǰ����ʵ����ָ��

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
//        //��������ͬ���޷���x,y��ֵ
//        this->x = x;
//        this->y = y;
//
//        //�����е�������ĺ�����������Ϊ����
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
//1.ջ�����������ڣ�
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
////������ָ�루unique_ptr��
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
//        ScopedPtr e = new Entity;  //��ʽת��
//        //Entity* e = new Entity;
//    }
//    return 0;
//}


//2.22
//1.����ָ�룺�Զ��������ڴ棨�Զ���ʵ��new,delete��
//     ->ͷ�ļ���#include<memory>

//1>unique_ptr:
//������ָ�룬�����������Զ�����ڴ�
//��ռ����Ȩ������ָ�룬����֤ͬһʱ����ֻ��һ��unique_ptr���Թ���һ������
//�����ܱ����ƣ������Ա��ƶ�

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
//        //ת�ƣ�
//        std::unique_ptr<Entity> e1 = std::move(e);
//    }
//    //��̬�ڴ����
//    std::unique_ptr<int> a = std::make_unique<int>(30);
//    std::cout << *a << std::endl;
//    return 0;
//}

//2>shared_ptr:
//��������Ȩ������ָ��,������shared_ptrʵ������ͬһ������
//��ͨ�����ü���������������������
//�м���ָ�����ü�����Ϊ���������ü���Ϊ0ʱ���ڴ汻���

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
//������ָ�룬������һ�������ڲ��������ü���������±�����
//��ͨ�����ڴ���shared_ptr֮���ѭ������

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
//        //�������Ƿ���ڣ�
//        std::cout << e0.lock() << std::endl;
//    }
//    return 0;
//}



//2.22
//1.�����뿽�����캯����
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
//    //�������캯����
//    //�������캯����һ�ֹ��캯�������Ĳ�����һ��ͬ���͵Ķ�������ã�ͨ����const���ã�
//    //���������Ǵ���һ���¶��󣬸ö�������һ������ĸ���
//    //��������󱻿���ʱ����
//
//    //1>Ĭ�Ͽ������캯����-->ǳ����
//    //����ָ�����ʱ����������ָ��ͬһ���ڴ��
//
//    /*String(const String& other)
//    {
//        m_buffer = other.m_buffer;
//        m_size = other.m_size;
//    }*/
//
//    //2>�Զ��忽�����캯����-->���
//    //����ָ�����ʱ����������ָ��ͬ�ڴ��
//
//    String(const String& other)/* = delete;*/  //ɾ���������캯�������ܿ��������
//    {
//        std::cout << "Coped the String!" << std::endl;
//        m_size = other.m_size;
//        m_buffer = new char[m_size + 1];
//        memcpy(m_buffer, other.m_buffer, m_size + 1);
//    }
//
//    ~String()
//    {
//        //�����ظ��ͷ�-->����δ������Ϊ
//        //ǳ����������ָ�������ʱ���׳����ظ��ͷ�
//        delete[] m_buffer;
//    }
//    //��Ԫ������
//    //��������ĳ�Ա�����������Է������˽�У�private���ͱ�����protected����Ա
//    //��ʽ��friend �������� ������(�����б�);
//    //�������д�����⣨ͨ������Ҳ����д������
//    //��Ԫ����ͨ������ʵ����Щ��Ҫֱ�ӷ������ڲ����ݵķǳ�Ա������������������������ȳ���
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
////���String����&��ÿ�ε���PrintString���Ḵ��һ��������β���ʵ�ε�һ�ݿ�����
////������ֹ�������Ҫʹ��������������������ͱ���һ��
////һ��ʼ<<�ĺ���������const,��PrintString�Ĳ�����const��
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
//}  //ǳ����ʱ�������������string,second�ͷţ�char*ָ��Ŀռ䱻�ͷ�����-->�������
//
////�ܽ᣺����ʹ��const & ����  -->���ⲻ��Ҫ�ĸ��ƣ��˷�����



//2.��ͷ������(->):
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


//2>����ƫ������
//#include<iostream>
//struct Vector3
//{
//    float x, y, z;  //ƫ������0��4��8
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
//1.��̬���飨std::vector��
//#include<iostream>
//#include<vector>  //ͷ�ļ�
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
//    //push_back()��Ӷ���
//    vertices.push_back({ 1,2,3 });
//    vertices.push_back({ 4,5,6 });
//    
//    //size()��ȡ�����С
//    for (int i = 0; i < vertices.size(); i++)
//    {
//        std::cout << vertices[i] << std::endl;
//    }
//
//    //ɾ��Ԫ��
//    //vertices.clear();  //ȫ��ɾ��
//    vertices.erase(vertices.begin() + 1);  //ɾ��ĳ��Ԫ��
//
//    //����һ����Χ-based forѭ������ C++11 �����һ�ּ򻯱��������ķ�ʽ
//    //���������Ǳ��� vertices �е�ÿһ��Ԫ�أ�����ÿ��Ԫ�ظ�ֵ������ v��Ȼ����ѭ�����д��� v
//    //���� v �� Vertex ��һ��������ÿ�ε������ᷢ��һ�ο�����Ϊ�˱��⿽��������ʹ������
//    //��ʽ������ ����������Χ���ʽ
//    for (Vertex& v : vertices)
//    {
//        std::cout << v << std::endl;
//    }
//
//
//    std::cin.get();
//    return 0;
//}


//2.��̬������Ż���
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
//    //һ������������
//    //1>ÿ����main�����д���Vextex����Ȼ���Ƶ�vector��
//    //2>vector�ĳ�ʼ����Ϊ1������ʱ�����ݣ�����+1��
//    //  �����ǰ�ԭ���ڴ��е����ݸ��Ƶ����ڴ��У���ɾ��ԭ�����ڴ棬ԭ���м���Ԫ�ؾ�Ҫ���Ƽ���
//    //std::vector<Vextex> vextices;
//    //vextices.push_back(Vextex(1, 2, 3));  //����1��
//    //vextices.push_back(Vextex(4, 5, 6));  //����2��
//    //vextices.push_back(Vextex(7, 8, 9));  //����3��
//
//
//    //�Ż�������0��
//    std::vector<Vextex> vextices;
//    //��ǰ���ú��ڴ棺
//    vextices.reserve(3);
//    //ʹ��emplace_back():
//    //1>push_back() ��һ����Ա���������ڽ�һ�����Ѵ��ڵĶ�����ӵ�������ĩβ
//    //������һ�������Ķ�����Ϊ����
//    //���ȣ����ᴴ��һ����ʱ����ͨ����ͨ���������ƶ����캯����
//    //Ȼ�󣬽������ʱ���󿽱����ƶ���������ĩβ
//    //�����ʱ��������
//    // 
//    //2>emplace_back() ��C++11����ĳ�Ա����������Ŀ������������ĩβֱ�ӹ������
//    //�Ӷ����ⲻ��Ҫ����ʱ���󴴽��Ϳ��� / �ƶ�����
//    //�����ܹ��캯���Ĳ�������ֱ��������������ڴ�λ���Ϲ������
//    vextices.emplace_back(1, 2, 3); 
//    vextices.emplace_back(4, 5, 6);  
//    vextices.emplace_back(7, 8, 9);  
//    std::cin.get();
//    return 0;
//}



//2.25��δ��ɣ�
//1.ʹ�ÿ⣨��̬���ӣ���


//2.ʹ�ö�̬�⣺


//3.������ʹ�ÿ⣺



//2.26
//1.����෵��ֵ��
//  1>����ʹ�����ô���/ָ�룺-->�׶ˣ���Ҫ��ǰ����ñ���
//  2>ʹ�����飨std::array/std::vector����-->�׶ˣ��������ͱ���һ��

//  3>tupleԪ��/pair�� -->�׶ˣ�ʹ�÷���ֵʱ���׻�����û�б�������ʾ��-->�ṹ����
//#include<iostream>
//#include<tuple>  //����tuple�Ķ���
//#include<utility>  //����pair�Ķ���
//#include<iomanip> //����fixed��setprecision


//tuple���԰��������ͬ���͵�����
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
//    //����tuple�е�Ԫ�أ�
//    std::cout << std::get<0>(result) << ',' << std::get<1>(result) << std::endl;
//    std::cin.get();
//    return 0;
//}


//pairֻ���԰���������ͬ���͵�����
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
//    //����pair�е�Ԫ�أ�
//    //std::cout << std::get<0>(result) << ',' << std::get<1>(result) << std::endl;
//    std::cout << result.first << ',' << result.second << std::endl;
//    std::cin.get();
//    return 0;
//}

//  4>ʹ�ýṹ�壺
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


//  ���䣺�ṹ���󶨣�C++17���룩�����Զ�tuple,pair,������Զ���ṹ��ʹ��
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
//    //***�ṹ���󶨣�
//    auto [x, y] = result;
//    //����tuple�е�Ԫ�أ�
//    std::cout << x << ',' << y << std::endl;
//    std::cin.get();
//    return 0;
//}



//2.28
//1.ģ�壨template��:��Ԫ��̣�
//ʵ���ϲ������ڣ�ֻ�е���������ʱ�Ŵ���

//#include<iostream>
//1>�����������ƵĴ��룺
//template<typename T>
//void Print(T value)
//{
//    std::cout << value << std::endl;
//}
//int main()
//{
//    //��ʽ��
//    Print(5);
//    //��ʽ��
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


//2.�꣺
//ʵ��Ӧ���У���ҪһЩ����ֻ��Debugģʽ�����У�����Releaseģʽ�²�����
//����Ŀ-����-c/c++ -Ԥ������-Ԥ�����������ж���Debug/Debug=1 
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

//�����д��һ�У�����ʹ��ת���ַ� \ ����
//#include<iostream>
//#define Main int main()\
//{\
//     std::cin.get();\
//     return 0;\
//}
//Main



//3.auto�ؼ��֣������Զ��Ƶ�����������-->���ڱ�������̫�������
//1>
//#include<iostream>
//#include<vector>
//int main()
//{
//    std::vector<std::string> strings;
//    strings.push_back("Apple");
//    strings.push_back("Orange");
//    //������(iterator)������ָ������ú��÷�
//    //begin()����һ����������ָ���һ��Ԫ�أ�end()����һ����������ָ�����һ��Ԫ�ص���һ��λ��
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
////std::unordered_map<,> ��ֵ�ԡ����ϡ�->��������
////���ڴ洢��ֵ��,���ڹ�ϣ��ʵ��
////ͨ�������Կ����ҵ���Ӧ��ֵ
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
//    //autoĬ�ϻ�������õ����ʣ�ֱ���Ƶ���������ָ���ԭʼ����
//    //��ҪʱҪ��ʽ��������&
//    std::cin.get();
//    return 0;
//}


//3.1
//1.����ָ�룺����ֵ��* ����ָ��������������
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



//2.lamda�������������������������������涨�壬���õ������ط�ȥ���������
//��ʽ��[](){} 
//��ʽ��[����������](������������) -> �������� { ������ }; 
//(->���ر������Բ�д����Ϊ�����״�return�ƶ�)
//[](=��ʾ�����б������д�ֵ���ݣ�&��ʾ�����б������д�ַ���ݣ�
//#include<iostream>
//#include<vector>
//#include<functional>  //std::function��ͷ�ļ�

//1>
//std::function �ṩ��һ��ͳһ�ķ�ʽ�����ò�ͬ�Ŀɵ��ö���
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
//    ////��ֵ���ݲ����޸ı�����ֵ-->ʹ��mutable���
//    std::cin.get();
//    return 0;
//}

//2>
//#include<algorithm>  //std::find_if()��ͷ�ļ�

//std::find_if ��һ��ͨ�õĲ����㷨��
//�������������� std::vector��std::list��std::array �ȣ��в��������ض������ġ���һ����Ԫ��
//������һ����Χ��ͨ��������ָ������һ��ν�ʣ�����һ��������
//ν��һ�����ܵ��������Ŀɵ��ö��󣬷���һ������ֵ��������� true�����ʾ��ǰԪ����������

//int main()
//{
//    std::vector<int> values = { 1,2,3,4,5 };
//    auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; });
//    std::cout << *it << std::endl;
//    return 0;
//}



//3.2
//1.���ƿռ䣺����������ͻ
//�౾��Ҳ��һ�������ռ䣬ʹ�þ�̬����ʱҪ����::
//ע�⣺������ʹ��using namespace std; ���Զ��Լ��Ŀ�ʹ�û���С��Χ����������
//�����������Բ�Ҫ��ͷ�ļ���ʹ��using namespace std; ͷ�ļ�������ʱ��������ش����
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
//    print("hello");  //"hello"������const char* ���ͣ�����Apple::print()ʱ��������ʽת��
//    std::cin.get();
//    return 0;
//}

//#include<iostream>
////�����ռ��Ƕ��
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
//    //�����ռ�ĸ�ֵ
//    //namespace a = Apple::function;
//    //a::print("hello");
//    std::cin.get();
//    return 0;
//}



//2.�̣߳�����ͬʱ���ж�������
//#include<iostream>
//#include<thread>  //�����ռ�this_thread��ͷ�ļ�
//#include<chrono>

//std::literals::chrono_literals �ṩ������ʱ�䵥λ����������������->��������֧�֣�
//h����ʾСʱ��std::chrono::hours��
//min����ʾ���ӣ�std::chrono::minutes��
//s����ʾ�루std::chrono::seconds��

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
//    //����join���̻߳�������ֱ��Ŀ���̣߳�worker������
//    worker.join();
//    std::cout << "finish the thread\n";
//    std::cout << "the id of the thread:" << std::this_thread::get_id() << std::endl;
//    std::cin.get();
//    return 0;
//}



//3.3
//1.��ʱ��������Ϊ�Ż����ܵ�ָ��

//1>
//#include<iostream>
//#include<chrono>
//#include<thread>
//int main()
//{
//    using namespace std::literals::chrono_literals;
//
//    //std::chrono::high_resolution_clock ��һ�ָ߾���ʱ�ӣ�ͨ�����ڲ���ʱ����
//    //now() �������ص�ǰʱ��㣨time_point��
//    auto start = std::chrono::high_resolution_clock::now();
//    std::this_thread::sleep_for(1s);
//    auto end = std::chrono::high_resolution_clock::now();
//
//    std::chrono::duration <float> duration = end - start;
//    //duration�������λ��count()ȡ����ֵ����
//    std::cout << duration.count() << "s" << std::endl;
//
//    std::cin.get();
//    return 0;
//}

//2>****�����������ڣ�
//#include<iostream>
//#include<chrono>
//
//class Timer
//{
//public:
//    //std::chrono::time_point ��һ����ʾʱ������ģ��
//    //��ͨ����ĳ��ʱ�ӣ��� std::chrono::steady_clock �� std::chrono::high_resolution_clock��һ��ʹ��
//    //time_point ��ʾһ�������ʱ�̣����硰����ʼ���е�ʱ�䡱��ĳ��������ɵ�ʱ�䡱
//    std::chrono::time_point<std::chrono::steady_clock > start, end;
//
//    //std::chrono::duration ��һ����ʾʱ��������ģ��
//    //���ڱ�ʾ����ʱ���֮��Ĳ�ֵ
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
//        std::cout << "hello\n";   //�ٶȸ���
//}
//int main()
//{
//    Function();
//    std::cin.get();
//    return 0;
//}



//3.4
//1.��ά���飺
//#include<iostream>
//int main()
//{
//    //һά���飺
//    int* arr = new int[5]();   //�յ�Բ���Ŵ����ʼ��Ϊ0
//    delete[] arr;
//
//    //��ά���飺�ڴ��ɢ�����ܵ�
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
//    //һά�����ʾ��ά���飺�ڴ漯��
//    int* p = new int[5 * 5];
//    //����
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


//ʵ�飺��ò�̫��
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
//    ////����
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



//2.����std::sort(����������������ν��)
//ν�ʣ���һ����������ʽ��������һ���������������������һ������ֵ
//���ݷ���ֵ�������ж�ĳ�������Ƿ�����

//#include<iostream>
//#include<vector>
//#include<algorithm>  //std::sort��ͷ�ļ�
//
//int main()
//{
//    std::vector<int> arr = { 5,2,4,1,3 };
//    //std::sort(arr.begin(), arr.end());  //ν��Ϊ��ʱ��Ĭ���������У�ֻ������������Ч��
//
//    //ν�ʷ���trueʱ��a����bǰ�棻����falseʱ��b����aǰ��
//    std::sort(arr.begin(), arr.end(), [](int a, int b)
//        {
//            //return a > b;  //����
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

