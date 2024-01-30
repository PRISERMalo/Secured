/*
** EPITECH PROJECT, 2024
** secured
** File description:
** hashtable generator
*/

#include "hashtable/hashtable.h"

int main(void)
{
    int (*hashf)(char *key, int len) = hash;
    hashtable_t *hasht = new_hashtable(hashf, CAPACITY);

    ht_insert(hasht, "mali:zjrefnqiluzrhfeamorgfiweorghwisdurghao_erghavçneèoa_zètyvbaert &'-trary_oyteg_yzr(tozeughiarhugaueghteghighrgauiehrguaherguhethuguhetgioetgjqierfqwmeo(ithzeuthrgçuzehyzçurhymeuthoauehrtpauç(hetzu(thqeurglisghxlirugtsroumgtmalo", "encorqkuyergfqyhrfliqusehgilseugtisdfgsdthgsetiglditsrtghisritughsliutghsrigsrlighsriughksdrgtslrighisrughsirughsiughsihtgislrgtdtghiserghksieghisughsidutghlsiughsitughsiudtghsieghsdiutghisudte une erreur que je dois gerer");
    ht_insert(hasht, "malimalo", "le best des goats");
    ht_insert(hasht, "alibaba", "encore un test de malade");
    ht_insert(hasht, "bobby", "quelle equipe ?");
    ht_insert(hasht, "MARC!", "BANQUE");
    ht_insert(hasht, "manimanon", "la meilleure des copines!");
    ht_insert(hasht, "", "encore un problème ouuuu ?");
    ht_insert(hasht, "iguan", "enft je crois que c'est bon");
    ht_insert(hasht, "malima", "encore une erreurue je dois gerer");
    ht_insert(hasht, "malio", "le st des goats");
    ht_insert(hasht, "alibaa", "encoren test de malade");
    ht_insert(hasht, "boby", "quellequipe ?");
    ht_insert(hasht, "MAR!", "BAUE");
    ht_insert(hasht, "manianon", "la meilleure s copines!");
    ht_insert(hasht, "iguan8", "encore un problème uu ?");
    ht_insert(hasht, "iguan", "enft je crois que c't bon");
    ht_dump(hasht);
    ht_delete(hasht, "manimanon");
    ht_delete(hasht, "iguan");
    ht_delete(hasht, "MARC!");
    ht_dump(hasht);
    delete_hashtable(hasht);
    // printf("Looking for \"%s\":\"%s\"\n", "iguan8", ht_search(hasht, "iguan8"));
    // printf("Looking for \"%s\":\"%s\"\n", "manimanon", ht_search(hasht, "manimanon"));
    return 0;
}
