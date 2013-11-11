#include <stdio.h>
#include "config.h"
#include "common.h"
#include <curl/curl.h>

int https(char * user, char* pass, char * domain)
{
    CURL *curl;
    CURLcode res;
    char userpass[2*LINELEN], url[BIGBUFLEN];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        sprintf(userpass, "%s:%s", user, pass);
        sprintf(url, "https://dynupdate.no-ip.com/nic/update?%s", domain);
        curl_easy_setopt(curl, CURLOPT_USERPWD, userpass);
        curl_easy_setopt(curl, CURLOPT_URL, url);

#ifdef SKIP_PEER_VERIFICATION
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#else
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
#endif

#ifdef SKIP_HOSTNAME_VERIFICATION
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#else
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 1L);
#endif

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
        {
            Msg("curl_easy_perform() failed: %s. Exiting...\n", curl_easy_strerror(res));
            exit(-1);
        }

        /* always cleanup */
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}
