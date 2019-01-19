//CEM BAYIR 160202066
//ÖZGÜR DEMÝR 160202072
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
int kayit_sil();
void kayit_sirala();

struct Ogrenci
{
    int ogrencino;
    int kayitsirasi;
    char ogretim[5];
    char ad[20];
    char soyad[20];

} kisiler[500],ogr1[500],ogr2[500],sil[500],yeni[500],dagit[500],dagitim[500],deneme[500],kucuk[10];


int main()
{

    int buyuk,i,j,n,d=0,say,sayma,m=0,s;
    int secim;
    clock_t start;
    start=clock();
    while(1)
    {
        printf("\n1: Listeyi Duzenle\n");
        printf("2: Kayit Sirala\n");
        printf("3: Kayit Ekle\n");
        printf("0: Cikis\n");
        printf("Secim?: ");
        scanf("%d", &secim);
        switch(secim)
        {
        case 0:{
        goto sini;

        }

        case 1:
        {
            printf("\nListe Guncellendi\n");
            kayit_sil();
            break;
        }
        case 2:
        {
            kayit_sirala();
            break;
        }
        case 3:
            {
                kayit_ekle();
                break;
        }

        default:
            printf("Yanlis Secim\n");

        };


    }


    clock_t end;
    end=clock();
    sini:
    printf("Listele fonksyonu icin gecen sure=%ld Microsaniye(µs)\n",(end-start)/(CLOCKS_PER_SEC));


    printf("Kac Sinif Olsun ? : ");
    scanf("%d",&n);
    int sinif[n];
    int toplam=0;
    int b;
    b=n;
    printf("\n\nSinif Kapasitelerini Giriniz\n");
    for(i=0; i<n; i++)
    {
        printf("%d. Sinifin Kapasitesi : ",i+1);
        scanf("%d",&sinif[i]);
    }
    FILE *son;
    son=fopen("ogretim1.txt","r");
    while(!feof(son))
    {
        fscanf(son,"%d",&dagit[d].ogrencino);
        fscanf(son,"%s",dagit[d].ad);
        fscanf(son,"%s",dagit[d].soyad);
        fscanf(son,"%d",&dagit[d].kayitsirasi);
        fscanf(son,"%s",dagit[d].ogretim);
        d++;
    }
    for(i=0;i<n;i++){
        toplam=toplam+sinif[i];
    }
    if(toplam<d){
        printf("Sinif kapasitelerini yanlis girdiniz.Tekrar giriniz.\n");
        for(i=0; i<n; i++)
    {
        printf("%d. Sinifin Kapasitesi : ",i+1);
        scanf("%d",&sinif[i]);
    }
    }
    printf("Birinci Ogretim Ogrenci Sayiyisi : %d dir\n\n",d);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(sinif[j]<sinif[j+1])
            {
                buyuk=sinif[j];
                sinif[j]=sinif[j+1];
                sinif[j+1]=buyuk;
            }
        }
    }
    printf("En Az Sinif Dagilimi 1.Ogretim\n\n");
    say=d;
    for(i=0; i<n; i++)
    {
        if(sinif[i]>say)
        {
            char bonus[10];;
            itoa(i+1,bonus,10);
            char bonus2[]="sinif";
            char bonus3[]="ogr1.txt";
            strcat(bonus2,bonus);
            strcat(bonus2,bonus3);
            FILE *karma;
            karma=fopen(bonus2,"w");
            for(s=0; s<sinif[i]; s++)
            {
                fprintf(karma,"%d\t%s\t%s\t%d\t%s\n",dagit[s+m].ogrencino,dagit[s+m].ad,dagit[s+m].soyad,dagit[s+m].kayitsirasi,dagit[s+m].ogretim);
            }
            printf("%d",say);
            fclose(karma);
            m=m+sinif[i];

            break;
        }


        char bonus[10];;
        itoa(i+1,bonus,10);
        char bonus2[]="Enazsinif";
        char bonus3[]="ogr1.txt";
        strcat(bonus2,bonus);
        strcat(bonus2,bonus3);
        FILE *karma;
        karma=fopen(bonus2,"w");
        for(s=0; s<sinif[i]; s++)
        {
            fprintf(karma,"%d\t%s\t%s\t%d\t%s\n",dagit[s+m].ogrencino,dagit[s+m].ad,dagit[s+m].soyad,dagit[s+m].kayitsirasi,dagit[s+m].ogretim);
        }
        sayma=say-sinif[i];
        say=sayma;
        printf("%d\t",sinif[i]);
        m=m+sinif[i];
        fclose(karma);
    }
    printf("\nEsit Sinif Dagilimi 1.Ogretim\n");
    say=d;
    m=0;
    for(i=n; i!=0; i--)
    {
        if(say%b==0 && say/b<=sinif[b-1])
        {
            for(b=n; b!=0; b--)
            {
                char bonus[10];
                itoa(i+1,bonus,10);
                char bonus2[]="Esitsinif";
                char bonus3[]="ogr1.txt";
                strcat(bonus2,bonus);
                strcat(bonus2,bonus3);
                FILE *karma;
                karma=fopen(bonus2,"w");
                for(s=0; s<sinif[b-1]; s++)
                {
                    fprintf(karma,"%d\t%s\t%s\t%d\t%s\n",dagit[s+m].ogrencino,dagit[s+m].ad,dagit[s+m].soyad,dagit[s+m].kayitsirasi,dagit[s+m].ogretim);
                }
                fclose(karma);
                printf("%d\t",say/b);
                m=m+sinif[i-1];
                break;
            }
        }
        else
        {
            char bonus[10];
            itoa(i+1,bonus,10);
            char bonus2[]="Esitsinif";
            char bonus3[]="ogr1.txt";
            strcat(bonus2,bonus);
            strcat(bonus2,bonus3);
            FILE *karma;
            karma=fopen(bonus2,"w");
            for(s=0; s<sinif[b-1]; s++)
            {
                fprintf(karma,"%d\t%s\t%s\t%d\t%s\n",dagit[s+m].ogrencino,dagit[s+m].ad,dagit[s+m].soyad,dagit[s+m].kayitsirasi,dagit[s+m].ogretim);
            }
            fclose(karma);
            sayma=say-sinif[i-1];
            say=sayma;
            printf("%d\t",sinif[i-1]);
            b--;
            m=m+sinif[i];
        }
    }
    fclose(son);
    int p=0;
    FILE *acik;
    acik=fopen("ogretim2.txt","r");
    while(!feof(acik))
    {
        fscanf(acik,"%d",&dagitim[p].ogrencino);
        fscanf(acik,"%s",dagitim[p].ad);
        fscanf(acik,"%s",dagitim[p].soyad);
        fscanf(acik,"%d",&dagitim[p].kayitsirasi);
        fscanf(acik,"%s",dagitim[p].ogretim);
        p++;
    }
    printf("\n\n2.Ogretim Sayii : %d dir\n",p);
    printf("\nEn Az Sinif Dagilimi 2.Ogretim\n");
    m=0;
    say=p+1;
    for(i=0; i<n-1; i++)
    {
        if(sinif[i]>say)
        {
            char bonus[10];;
            itoa(i+1,bonus,10);
            char bonus2[]="Enazsinif";
            char bonus3[]="ogr2.txt";
            strcat(bonus2,bonus);
            strcat(bonus2,bonus3);
            FILE *karma;
            karma=fopen(bonus2,"w");
            for(s=0; s<sinif[i]; s++)
            {
                fprintf(karma,"%d\t%s\t%s\t%d\t%s\n",ogr2[s+m].ogrencino,ogr2[s+m].ad,ogr2[s+m].soyad,ogr2[s+m].kayitsirasi,ogr2[s+m].ogretim);
            }
            printf("%d",say);
            fclose(karma);
            m=m+sinif[i];

            break;
        }
        char bonus[10];;
        itoa(i+1,bonus,10);
        char bonus2[]="Enazsinif";
        char bonus3[]="ogr2.txt";
        strcat(bonus2,bonus);
        strcat(bonus2,bonus3);
        FILE *karma;
        karma=fopen(bonus2,"w");
        for(s=0; s<sinif[i]; s++)
        {
            fprintf(karma,"%d\t%s\t%s\t%d\t%s\n",ogr2[s+m].ogrencino,ogr2[s+m].ad,ogr2[s+m].soyad,ogr2[s+m].kayitsirasi,ogr2[s+m].ogretim);
        }
        sayma=say-sinif[i];
        say=sayma;
        printf("%d\t",sinif[i]);
        m=m+sinif[i];
        fclose(karma);
        if(say==0)
            break;
    }
    printf("\nEsit Sinif Dagilimi 2.Ogretim\n\n");
    say=p+1;
    m=0;
    for(i=n; i!=0; i--)
    {
        if(say%b==0 && say/b<=sinif[b-1])
        {
            for(b=n; b!=0; b--)
            {
                char bonus[10];
                itoa(i+1,bonus,10);
                char bonus2[]="Esitsinif";
                char bonus3[]="ogr2.txt";
                strcat(bonus2,bonus);
                strcat(bonus2,bonus3);
                FILE *karma;
                karma=fopen(bonus2,"w");
                for(s=0; s<sinif[b-1]; s++)
                {
                    fprintf(karma,"%d\t%s\t%s\t%d\t%s\n",ogr2[s+m].ogrencino,ogr2[s+m].ad,ogr2[s+m].soyad,ogr2[s+m].kayitsirasi,ogr2[s+m].ogretim);
                }
                fclose(karma);
                printf("%d\t",say/b);
                m=m+sinif[i-1];
                break;
            }
        }
        else
        {
            char bonus[10];
            itoa(i+1,bonus,10);
            char bonus2[]="Esitsinif";
            char bonus3[]="ogr2.txt";
            strcat(bonus2,bonus);
            strcat(bonus2,bonus3);
            FILE *karma;
            karma=fopen(bonus2,"w");
            for(s=0; s<sinif[b-1]; s++)
            {
                fprintf(karma,"%d\t%s\t%s\t%d\t%s\n",ogr2[s+m].ogrencino,ogr2[s+m].ad,ogr2[s+m].soyad,ogr2[s+m].kayitsirasi,ogr2[s+m].ogretim);
            }
            fclose(karma);
            sayma=say-sinif[i-1];
            say=sayma;
            printf("%d\t",sinif[i-1]);
            b--;
            m=m+sinif[i];
        }
        if(say==0)
            break;
    }
     printf("\n\nTum ogrenciler yerlestirilebilmistir.\n\n");

    fclose(acik);

    return 0;

}
void kayit_ekle(){

int m=0;
int i;

FILE *dosy=fopen("listem.txt","r");
FILE *dosy2;
while(!feof(dosy))
    {
        fscanf(dosy,"%d",&kisiler[m].ogrencino);
        fscanf(dosy,"%s",kisiler[m].ad);
        fscanf(dosy,"%s",kisiler[m].soyad);
        fscanf(dosy,"%d",&kisiler[m].kayitsirasi);
        fscanf(dosy,"%s",kisiler[m].ogretim);
        m++;

    }
printf("\nGirilecek Ogrencinin\n");
    printf("Ogrenci numarasini girin:");
    scanf("%d",&kisiler[m].ogrencino);
    fflush(stdin);
    printf("Adini girin:");
    scanf("%s",kisiler[m].ad);
    fflush(stdin);
    printf("Soyadini girin:");
    scanf("%s",kisiler[m].soyad);
    fflush(stdin);
    printf("Kayitsirasini girin:");
    scanf("%d",&kisiler[m].kayitsirasi);
    fflush(stdin);
    printf("Ogretim turunu girin:");
    scanf("%s",kisiler[m].ogretim);
    fflush(stdin);
m++;
fclose(dosy);

dosy2=fopen("listem.txt","w");
for(i=0; i<m; i++)
    {
        fprintf(dosy2,"%d\t\t%s\t\t%s\t\t%d\t\t%s\n",kisiler[i].ogrencino,kisiler[i].ad,kisiler[i].soyad,kisiler[i].kayitsirasi,kisiler[i].ogretim);

    }
    fclose(dosy2);

}

int kayit_sil()
{
    int n=-1,i,j,x,y,l=0;
    int m=0;
    FILE *dosya=fopen("listem.txt","r");
    FILE *dosyam;

    if(dosya==NULL)
    {
        printf("Dosya acilamadi!\n");
        return 0;
    }


    while(!feof(dosya))
    {
        fscanf(dosya,"%d",&kisiler[m].ogrencino);
        fscanf(dosya,"%s",kisiler[m].ad);
        fscanf(dosya,"%s",kisiler[m].soyad);
        fscanf(dosya,"%d",&kisiler[m].kayitsirasi);
        fscanf(dosya,"%s",kisiler[m].ogretim);
        m++;

    }
    for(i=0; i<m-1; i++)
    {
        for(j=i+1; j<m-1; j++)
        {
            if(strcmp(kisiler[i].ad,kisiler[j].ad)==0 && strcmp(kisiler[i].soyad,kisiler[j].soyad)==0)
            {
                n=j;
                l++;
            }
        }
    }
    if(l==0)
    {
        fclose(dosya);
        return 0;
    }

    for(x=0; x<n; x++)
    {
        sil[x].ogrencino=kisiler[x].ogrencino;
        strcpy(sil[x].ad,kisiler[x].ad);
        strcpy(sil[x].soyad,kisiler[x].soyad);
        sil[x].kayitsirasi=kisiler[x].kayitsirasi;
        strcpy(sil[x].ogretim,kisiler[x].ogretim);
    }

    for(i=n+1; i<m-1; i++)
    {
        sil[i-1].ogrencino=kisiler[i].ogrencino;
        strcpy(sil[i-1].ad,kisiler[i].ad);
        strcpy(sil[i-1].soyad,kisiler[i].soyad);
        sil[i-1].kayitsirasi=kisiler[i].kayitsirasi;
        strcpy(sil[i-1].ogretim,kisiler[i].ogretim);
    }

    fclose(dosya);

    dosyam=fopen("listem.txt","w");

    if(dosya==NULL)
    {
        printf("Dosya acilamadi!\n");
        return 0;
    }

    for(y=0; y<m-2; y++)
    {
        fprintf(dosyam,"%d\t\t%s\t\t%s\t\t%d\t\t%s\n",sil[y].ogrencino,sil[y].ad,sil[y].soyad,sil[y].kayitsirasi,sil[y].ogretim);

    }
    fclose(dosyam);

    printf("\n%s %s silindi",kisiler[n].ad,kisiler[n].soyad);

    kayit_sil();
    return 0;

}
void kayit_sirala()
{
    FILE *dosyam2=fopen("listem.txt","r");
    FILE *dosyam3;
    FILE *dosyam4;
    int y=0,n=0,i,j,x=0,t=0,z=0;
    char a[10]="I",b[10]="II";

    if(dosyam2==NULL)
    {
        printf("Dosya acilamadi!\n");
        return 0;
    }


    while(!feof(dosyam2))
    {

        fscanf(dosyam2,"%d",&sil[y].ogrencino);
        fscanf(dosyam2,"%s",sil[y].ad);
        fscanf(dosyam2,"%s",sil[y].soyad);
        fscanf(dosyam2,"%d",&sil[y].kayitsirasi);
        fscanf(dosyam2,"%s",sil[y].ogretim);
        y++;

    }


    for(i=0; i<y-1; i++)
    {
        if(strcmp(sil[i].ogretim,a)==0)
        {
            ogr1[t]=sil[i];
            t++;
            x++;
        }
        if(strcmp(sil[i].ogretim,b)==0)
        {
            ogr2[z]=sil[i];
            z++;
            n++;
        }
    }

    for(t=0; t<x; t++)
    {
        if(ogr1[t].ogrencino==0)
        {
            ogr1[t].ogrencino=1701000+ogr1[t].kayitsirasi;
        }
    }

    for(z=0; z<n; z++)
    {
        if(ogr2[z].ogrencino==0)
        {
            ogr2[z].ogrencino=1702000+ogr2[z].kayitsirasi;
        }
    }
    for(i=0; i<x; i++)
    {
        for(j=0; j<x-1; j++)
        {
            if(ogr1[j].ogrencino>ogr1[j+1].ogrencino)
            {
                kucuk[0]=ogr1[j];
                ogr1[j]=ogr1[j+1];
                ogr1[j+1]=kucuk[0];
            }
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(ogr2[j].ogrencino>ogr2[j+1].ogrencino)
            {
                kucuk[0]=ogr2[j];
                ogr2[j]=ogr2[j+1];
                ogr2[j+1]=kucuk[0];
            }
        }
    }

    fclose(dosyam2);

    dosyam3=fopen("ogretim1.txt","w");
    dosyam4=fopen("ogretim2.txt","w");
    for(t=0; t<x; t++)
    {
        fprintf(dosyam3,"%d\t\t",ogr1[t].ogrencino);
        fprintf(dosyam3,"%s\t\t",ogr1[t].ad);
        fprintf(dosyam3,"%s\t\t",ogr1[t].soyad);
        fprintf(dosyam3,"%d\t\t",ogr1[t].kayitsirasi);
        fprintf(dosyam3,"%s\t\n",ogr1[t].ogretim);

    }
    for(z=0; z<n; z++)
    {
        fprintf(dosyam4,"%d\t\t",ogr2[z].ogrencino);
        fprintf(dosyam4,"%s\t\t",ogr2[z].ad);
        fprintf(dosyam4,"%s\t\t",ogr2[z].soyad);
        fprintf(dosyam4,"%d\t\t",ogr2[z].kayitsirasi);
        fprintf(dosyam4,"%s\t\n",ogr2[z].ogretim);

    }
fclose(dosyam3);
fclose(dosyam4);

}

