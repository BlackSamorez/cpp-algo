#include <string>

class IOWrapper{
    handle_t handle;
    
public:
    IOWrapper() = delete;
    IOWrapper(handle_t handle){
        this->handle = handle;
    }
    
    IOWrapper(const IOWrapper&) = delete;
    IOWrapper(IOWrapper&& rls){
        handle = rls.handle;
    }

    IOWrapper& operator=(const IOWrapper&) = delete;
    void operator=(IOWrapper&& rhs){
        handle = rhs.handle;
        rhs.handle = kNullHandle;
    }

    void Write(const std::string& content){
        raw_write(handle, content);
    }
    ~IOWrapper(){
        if (handle != kNullHandle)
            raw_close(handle);
    }
};

