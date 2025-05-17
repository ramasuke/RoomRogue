#include "ApplicationBase.h"
application_base::application_base()
{
    instance_ = this;
}
application_base& application_base::get_instance()
{
    return *instance_;
}