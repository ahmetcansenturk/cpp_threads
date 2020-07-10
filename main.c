#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define elemansayisi 20
#define Th_max 4
int dizim[elemansayisi] ={5,10,85,45,36,99,77,11,158
,-10,12,97,1997,55,756,94,83,41,64,-77};
int min_num[Th_max] = { 0 };
int thread_no = 0;
//dizinin en küçük elemanını bulan fonksiyon
void enkucuksayi(void* arg)
{
    int i, num = thread_no++;
    int enksayi = 100000;
// bu kısım 4 adet olan thread e diziyi eşit biçimde bölmeye yarıyor.
// daha sonra ana fonksiyonda bunlardan dönen 4 değer arasında en küçüğü bulup yazdırıyoruz.
    for (i = num * (elemansayisi /4); i < (num + 1) * (elemansayisi / 4); i++) {
        if (dizim[i] < enksayi)
            enksayi = dizim[i];
    }
    min_num[num] = enksayi;
}
int main()
{
    int enkucuk = 0;
    int i;
 //thread dizisi 
    pthread_t threads[Th_max];

//thread dizisinin içini dolduruyoruz.
//kullanacağı fonksiyonu belirtiyoruz.
    for (i = 0; i < Th_max; i++)
        pthread_create(&threads[i], NULL,
                       enkucuksayi, (void*)NULL);
                        for (i = 0; i < Th_max; i++)
        pthread_join(threads[i], NULL);
//thread lerden dönen  4 elaman arasından en küçük olanı belirleyip ekrana yazdırıyoruz 
    for (i = 0; i < Th_max; i++) {
        if (min_num[i] < enkucuk)
            enkucuk = min_num[i];
    }
 printf("Dizinin en küçük elemanı : %d", enkucuk);

    return 0;
}
