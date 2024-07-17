#include "ChainSaw.h"

int main(void){
    auto app = new CSE::Application();
    app->RunContext(false);
    CSE_DELETE(app);
    return 0;
}
