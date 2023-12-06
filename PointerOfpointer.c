#include <stdio.h>

void changeValue(int **ptr) { // Bir pointer vardı kendi içerisinde bir değişkeni işaret eden (adresini tutan)
							  // İşte sana onun adresini gönderiyorum sende pointer ın adresini tut.
							  // artık ptr nin kendisi pointer ın adresidir. 
							  // *ptr yazarsam o pointerın içerisinde sakladığı adres değeri gelir.
							  // **ptr yazarsam pointerın sakladığı adresin içindeki değere erişebilir ve işlem yapabilir.
							  
    **ptr = 59;
    
    // Daha başka kullanım tarzı ise : Diyelimki içerisine farklı bir değişken oluşturup değer atamak istediniz.
    // O zaman da pointer ın tuttuğu adres değerini yeni oluşturduğunu adres değeri ile değiştirmeniz yeterli olacaktır.
    
    int yeniDegisken = 1212;
    
    *ptr = &yeniDegisken; // Bu ifade az önce işaretçiye yeni göstermesi(işaret etmesi) gereken adresi verdi.
    					  //Daha sonra yeni gösterdiği adrese ulaşıp işlemler yapmak kullanıcıya kalmış olan bir durum.
    					  //işlem sırasına bakıldığı takdirde en son after da yazacak sayı 1212 değeri olacaktır 
}


void changeValue2(int *ptr) {
	// ptr , bizim değer sakladığımız değişkeni tutan, iaşret eden bellek üzerinde bir adrestir.
	// *ptr denildiği vakit tuttuğu adresdeki o adresin içinde saklanan değere ulaşır.
	// global olarak bir değişiklik yapılması isteniyorsa *ptr 'nin içerisine değerler gönderilir
	// ya da o saklanan değerle matematiksel işlemler yapılması isteniyorsa (*ptr) denilerek fonksiyon içerisinde kullanılır
    int new_value = 42;
    *ptr = new_value;
}

int main() {
    int value = 10;
    int *ptr = &value; // Bir int işaretçisi

    printf("Before: %d\n", *ptr); //10 değeri gelir
	changeValue2(ptr);
	printf("After: %d\n", *ptr); //42 değeri gelir
	
	printf("\n\n");
	
	printf("Before: %d\n", *ptr); // 42 değeri gelir
    changeValue(&ptr); //Eğer biz tanımladığımız pointer'ın adresini gönderiyorsak o zaman iki katman ortaya çıkar
    				   //Yani adres tutan bir değişkenin adresi. Bu yüzden de ilk pointer a ulaşmak için ilgili fonksyona gidilir.
    printf("After: %d\n", *ptr);

    return 0;
}
