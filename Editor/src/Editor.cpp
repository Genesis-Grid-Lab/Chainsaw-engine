#include "Editor.h"

int main(void){
    auto app = new CSE::Application();
    app->AttachLayer<Editor>();
    app->RunContext(false);
    CSE_DELETE(app);
    return 0;
}
