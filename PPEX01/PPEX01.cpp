// PPEX01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>


namespace MuSoeun
{
    class Scene {
    
        // 화면 배열
        char* screenBuffer;
        // 화면의 크기
        int screenWidth;
        int screenHeight;
        // Scene에서 사용하는 Object 리스트
        std::vector<Object> objectList;

    public:
        // 생성자
        Scene(int width, int height) : screenWidth(width), screenHeight(height) {
            screenBuffer = new char[screenWidth * screenHeight];
            objectList.clear();
        }

        // 소멸자
        ~Scene() {
            delete[] screenBuffer;
        }

        // Object를 Scene에 추가하는 함수
        void AddObject(const Object& object) {
            objectList.push_back(object);
        }

        // Object를 Scene에서 제거하는 함수
        void RemoveObject(const Object& object) {
            // Object 리스트에서 해당 object를 찾아 제거
            // ...
        }

        // Active한 Object의 Render를 호출하고 화면을 그리는 함수
        void Draw() {
            // ScreenBuffer 초기화
            ClearScreenBuf();

            // Active한 Object의 Render 호출
            for (const Object& object : objectList) {
                if (object.IsActive()) {
                    object.Render(screenBuffer, screenWidth, screenHeight);
                }
            }

            // 화면 출력
            PrintScreenBuf();
        }

        // 화면을 초기화하는 함수
        void ClearScreenBuf() {
            for (int i = 0; i < screenWidth * screenHeight; i++) {
                screenBuffer[i] = ' ';
            }
        }

        // 화면을 출력하는 함수
        void PrintScreenBuf() {
            for (int y = 0; y < screenHeight; y++) {
                for (int x = 0; x < screenWidth; x++) {
                    std::cout << screenBuffer[y * screenWidth + x];
                }
                std::cout << std::endl;
            }
        }
    };
    class Object {
        int posX;
        int posY;
        float scale;
        float rotation;
        bool isActive;

    public:
        bool IsActive() const {
            return isActive;
        }
        Object(int x, int y) : posX(x), posY(y), scale(1.0f), rotation(0.0f) {}

        // Object의 모양을 Render하는 함수
        virtual void Render(char* screenBuffer, int screenWidth, int screenHeight) = 0;
    
    

    // Object의 위치를 설정하는 함수
    void SetPosition(int x, int y) {
        posX = x;
        posY = y;
    }

    // Object의 크기를 설정하는 함수
    void SetScale(float s) {
        scale = s;
    }

    // Object의 회전을 설정하는 함수
    void SetRotation(float r) {
        rotation = r;
    }
};

// SnakeBody 클래스 정의
class SnakeBody : public Object {
public:
    SnakeBody(int x, int y) : Object(x, y) {}

    // SnakeBody의 모양을 Render하는 함수
    void Render(char* screenBuffer, int screenWidth, int screenHeight) {
        // SnakeBody의 모양을 ScreenBuffer에 그리는 로직 구현
        // ...
    }
};
    //class Scene
    //{
    //public:
    //    int width;
    //    int height;
    //    std::vector<Object> objList;

    //    //screenBuf[width + (width * height)];

    //    char* screenBuf;
    //    std::vector<Object*> objects;
    //    void Draw()
    //    {
    //        for (Object* object : objects) {
    //            if (object->IsActive()) {
    //                object->Render();
    //            }
    //        }

    //        
    //        for (int y = 0; y < height; ++y) {
    //            for (int x = 0; x < width; ++x) {
    //                char pixel = screenBuf[y * width + x];
    //                
    //                std::cout << pixel;
    //            }
    //            std::cout << std::endl;
    //        }
    //    }
    //    
    //    void InitScreenBuf()
    //    {
    //        screenBuf = new char[(width + 1) * height + 5];

    //        for (int i; i < height; i++)
    //        {
    //            screenBuf[(width + 1) + (width + 1) * i - 1] = '\n';

    //        }
    //        screenBuf[(width + 1) + (width + 1) * (height - 1) - 1] = '\0';
    //    }
    //    void ReleaseScreenBuf()
    //    {
    //        if (screenBuf != nullptr)
    //        {
    //            delete(screenBuf);
    //        }
    //    }

    //    void DrawScreenBuf()
    //    {
    //        std::cout << screenBuf;
    //    }
    //};

    /*class Object
    {
        bool IsActive;
        virtual void Render();
    };*/

    class Component //Unity MonoBehavior
    {
        void Start();
        void Update();
    };
}

int main()
{
    while (1)
    {

    }

    return 0;
}
