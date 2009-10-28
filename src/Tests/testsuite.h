// This file contains interfaces to a set of gamma tests
#include "gamma.h"
#include <string>

class GammaTest

{

public:

static int iso_test();

static int fid_test(std::string & sysfile);

static int spinecho_test(std::string & sysfile);

static int spinecho_realpulse_test(std::string & sysfile, std::string & pulse180file);

static int press_realpulses_test(std::string & sysfile, std::string & pulse180file);

static int fid_exchange_test(std::string & sysfile);

};
