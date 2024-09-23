#include <stdio.h>
#include <stdlib.h>
#include <openssl/bio.h> /* BasicInput/Output streams */
#include <openssl/err.h> /* errors */
#include <openssl/ssl.h> /* core library */

int main()
{

    BIO *cbio, *out;
    int len;
    char tmpbuf[1024];
    ERR_load_crypto_strings();
    cbio = BIO_new_connect("https://locallhost.com/:https");
    out = BIO_new_fp(stdout, BIO_NOCLOSE);
    if(BIO_do_connect(cbio) <= 0) {
       fprintf(stderr, "Error connecting to server\n");
       ERR_print_errors_fp(stderr);
       /* whatever ... */
    }
    BIO_puts(cbio, "GET / HTTP/1.0\n\n");
    for(;;) {
       len = BIO_read(cbio, tmpbuf, 1024);
       if(len <= 0) break;
       BIO_write(out, tmpbuf, len);
    }
    BIO_free(cbio);
    BIO_free(out);
}