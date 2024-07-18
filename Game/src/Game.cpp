#include <ChainSaw.h>

int main(void)
{
    using namespace CSE;
    auto app = new Application();
    app->RunContext(true);
    CSE_DELETE(app);
    return 0;
}
