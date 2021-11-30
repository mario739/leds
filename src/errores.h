void RegistraMensaje(int gravedad, const char *funcion, int linea, const char * mensaje);
typedef void (*logger)(int gravedad, const char *funcion, int linea, const char * mensaje);

void StatusLed(const char *mensaje);