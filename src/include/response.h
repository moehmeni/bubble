// TODO: Replace C structs to C++ classes
/** HTTP Response representor */
struct Response
{
    int status_code;
    char *status_message;
    char *headers;
};
