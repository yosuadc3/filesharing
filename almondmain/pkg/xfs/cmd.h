#pragma once

//#include "lib/XFSAPI.H"
#include "XFSAPI.H"
// #include <string>
// #include <map>
#include "stdafx.h"
//#pragma comment(lib, "user32.lib")
#define HKEY_LOGICAL_SERVICES L".DEFAULT\\XFS\\LOGICAL_SERVICES"
#define WFSC_BAD_CMD 0x42
#define APPID "almond"
#define CMD_COUNT(x) (sizeof(x)/sizeof(cmd_t))

static DWORD keyCount;
static DWORD subKeyCount;
extern int subKeyRegisteredCount;

void setKeyCount(DWORD x);
DWORD getKeyCount();

typedef HRESULT(*handler_t)(int, char**);
typedef void(*help_fn)();

typedef struct cmd_ {
    const char* name;
    const char* help;
    handler_t   func;
    help_fn     more;
} cmd_t;

//union xfsServiceData {
//    HSERVICE id;
//    char logical_name[50];
//    char class_name[3];
//};
//
//struct xfsServiceNode {
//    union xfsServiceData xfsService;
//    struct xfsServiceNode* next;
//    struct xfsServiceNode* prev;
//};
char* getLocalDate();

struct xfsService {
    HSERVICE id;
    char* logical_name;
    char* class_name;
    //char logical_name[50];
    //char class_name[4];
};

extern struct xfsService* listXFSService;

// class Service {
// public:
//     std::string name;
//     // TODO: Other metadata...
//     HSERVICE    handle;

//     Service(std::string name, HSERVICE h) : name(name), handle(h) {}
//     ~Service() {
//         if (handle) WFSClose(handle);
//     }
// };

void handle(char* args);
HRESULT dispatch(cmd_t* fdt, int count, int argc, char** argv);

// comment sementara  Service* get_service(HSERVICE id);
// comment sementara  void     del_service(Service* svc);

// comment sementara  void lock(Service* svc);
// comment sementara  void unlock(Service* svc);

void init_cdm();
void init_cim();
void init_ptr();
void init_idc();

const char* getErrorMessage(HRESULT res);
void scan_reg();
int connect_xfs_man();
void registerEvent(HSERVICE handle, LPSTR serviceName);
BOOL getNotif();
//char* checkEvent(UINT message, DWORD dwEventID, LPVOID lpBuffer, HSERVICE handle);

//void disconnect_xfs_man();