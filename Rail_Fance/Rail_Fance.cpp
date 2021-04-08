#include <iostream>
#include <string>

using namespace std;

class algorithm
{
    public:
    string encrypt(int key, string mensaje)
    {
        int i = 0;
        int distancia = (key - 1) * 2;
        int length = mensaje.length();
        string encrypted(mensaje.length(), ' ');

        for (int j = 0; j < key; j++)
        {
            for (int k = 0; j + (distancia * k) - (2 * j) < length; k++)
            {
                if ((j % (distancia / 2) != 0) && (k != 0))
                {
                    encrypted[i] = mensaje[j + (distancia * k) - (2 * j)];
                    i++;
                }
                if ((j + (distancia * k)) < length)
                {
                    encrypted[i] = mensaje[j + (distancia * k)];
                    i++;
                }
            }
        }
        return encrypted;
    }

    string decrypt(int key, string mensaje)
    {
        int i = 0;
        int distancia = (key - 1) * 2;
        int length = mensaje.length();
        string decrypted(mensaje.length(), ' ');

        for (int j = 0; j < key; j++)
        {
            for (int k = 0; j + (distancia * k) - (2 * j) < length; k++)
            {
                if (j % (distancia / 2) != 0 && k != 0)
                {
                    decrypted[j + (distancia * k) - (2 * j)] = mensaje[i];
                    i++;
                }
                if (j + (distancia * k) < length)
                {
                    decrypted[j + (distancia * k)] = mensaje[i];
                    i++;
                }
            }
        }
        return decrypted;
    }
};

int main()
{
    string le_message = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Risus commodo viverra maecenas accumsan lacus vel facilisis volutpat est. Dis parturient montes nascetur ridiculus mus mauris vitae ultricies leo. Sed id semper risus in hendrerit gravida. Posuere ac ut consequat semper viverra nam libero. Neque laoreet suspendisse interdum consectetur. Tincidunt vitae semper quis lectus. Amet risus nullam eget felis. Erat nam at lectus urna duis convallis convallis tellus. Ornare arcu dui vivamus arcu felis. Urna nunc id cursus metus aliquam. Semper risus in hendrerit gravida rutrum. Semper risus in hendrerit gravida. Pretium aenean pharetra magna ac placerat vestibulum lectus mauris ultrices. Venenatis lectus magna fringilla urna. Fringilla phasellus faucibus scelerisque eleifend donec pretium. Volutpat commodo sed egestas egestas. Ut ornare lectus sit amet est. Nulla at volutpat diam ut venenatis tellus. In massa tempor nec feugiat nisl pretium. Curabitur gravida arcu ac tortor. Tortor consequat id porta nibh. Non nisi est sit amet facilisis magna etiam tempor. In ante metus dictum at tempor commodo. Augue neque gravida in fermentum et sollicitudin ac orci. Blandit cursus risus at ultrices mi tempus imperdiet. Justo eget magna fermentum iaculis eu non diam. Purus in mollis nunc sed id. At imperdiet dui accumsan sit amet nulla facilisi morbi. Arcu felis bibendum ut tristique et egestas quis ipsum suspendisse. Duis at tellus at urna condimentum mattis pellentesque id nibh. Nibh ipsum consequat nisl vel pretium lectus quam id. Turpis egestas sed tempus urna. Pellentesque elit ullamcorper dignissim cras. Posuere sollicitudin aliquam ultrices sagittis. Pellentesque habitant morbi tristique senectus. Tortor consequat id porta nibh venenatis cras sed felis eget. Habitasse platea dictumst quisque sagittis purus sit amet volutpat. Bibendum enim facilisis gravida neque convallis. Mattis aliquam faucibus purus in massa tempor nec feugiat. Porttitor leo a diam sollicitudin. Dignissim enim sit amet venenatis urna cursus eget nunc. Egestas congue quisque egestas diam in arcu cursus euismod quis. Et malesuada fames ac turpis. Id diam vel quam elementum. Pellentesque habitant morbi tristique senectus et netus et malesuada fames. Sit amet consectetur adipiscing elit duis. Fermentum leo vel orci porta non pulvinar neque laoreet. Id aliquet risus feugiat in ante metus dictum. Dui faucibus in ornare quam viverra orci. Eget sit amet tellus cras adipiscing. Tristique senectus et netus et malesuada fames ac. Nulla facilisi cras fermentum odio eu feugiat pretium. Orci nulla pellentesque dignissim enim sit amet venenatis urna. Potenti nullam ac tortor vitae purus. Tristique risus nec feugiat in fermentum posuere urna nec. Amet risus nullam eget felis eget nunc. Non arcu risus quis varius quam quisque id diam. Netus et malesuada fames ac turpis. Nisi quis eleifend quam adipiscing vitae proin sagittis. Egestas dui id ornare arcu odio ut sem. Nec nam aliquam sem et tortor. Nisl pretium fusce id velit. Ornare arcu dui vivamus arcu felis bibendum ut tristique et. Metus aliquam eleifend mi in. Feugiat nisl pretium fusce id velit ut tortor pretium. Sit amet justo donec enim diam vulputate. Porttitor leo a diam sollicitudin tempor id. Malesuada fames ac turpis egestas maecenas pharetra. Consequat interdum varius sit amet mattis vulputate enim nulla. Maecenas pharetra convallis posuere morbi leo urna molestie at. Ornare suspendisse sed nisi lacus sed viverra tellus. Proin libero nunc consequat interdum varius sit amet mattis vulputate. Suspendisse in est ante in. Fringilla urna porttitor rhoncus dolor purus. Amet cursus sit amet dictum sit amet justo. Faucibus nisl tincidunt eget nullam. Diam in arcu cursus euismod quis viverra nibh cras pulvinar. Mi proin sed libero enim sed faucibus. Rutrum quisque non tellus orci ac auctor augue. Pharetra convallis posuere morbi leo urna molestie at elementum eu. Lectus quam id leo in vitae turpis massa sed elementum. Eget velit aliquet sagittis id consectetur. Nunc non blandit massa enim nec dui. Neque convallis a cras semper auctor neque vitae tempus quam. Urna nunc id cursus metus aliquam eleifend. Elit pellentesque habitant morbi tristique. Vulputate mi sit amet mauris commodo quis imperdiet. Sed velit dignissim sodales ut eu sem integer vitae. Dolor magna eget est lorem ipsum dolor sit amet. Blandit turpis cursus in hac. Semper feugiat nibh sed pulvinar proin gravida hendrerit. Posuere morbi leo urna molestie at elementum. Ut diam quam nulla porttitor. Dolor morbi non arcu risus quis. Interdum velit euismod in pellentesque massa. Tellus mauris a diam maecenas sed enim ut sem. Adipiscing elit ut aliquam purus sit. Facilisis sed odio morbi quis. Et netus et malesuada fames.";
    //for (int i = 2; i < 30; i++)
    //{
        //for (int j = 0; j < 100; j++)
        //{
        //    string message(le_message, 0, j);
        //    int key = i;
    string message(le_message, 0, 50); //SI SE VA A DESCOMENTAR LAS OTRAS LINEAS COMENTAR ESTA Y LA DE ABAJO
    int key = 5;
    algorithm emisor;
    algorithm receptor;
    string mensaje_encriptado = emisor.encrypt(key, message);
    string mensaje_desencriptado =  receptor.decrypt(key, mensaje_encriptado);
    cout << endl;
    cout << "El mensaje es: " << message << endl << endl;
    cout << "El mensaje encriptado es: " << mensaje_encriptado << endl << endl;
    cout << "El mensaje descencriptado es: " << mensaje_desencriptado << endl;
            //if (mensaje_desencriptado == message) 
            //{
            //    cout << "Congrats, so far so good!" << endl;
            //    cout << "Key:" << key << '\t' << "Message length: " << message.length() << endl << "Message: " << message << endl << endl <<  "Encrypted: " << mensaje_encriptado << endl << endl << "Decrypted: " << mensaje_desencriptado << endl;
            //}
            //else
            //{
            //    cout << "Well it doesn't seems to work!." << endl;
            //}
        //}    
    //}

    cout << endl;

    return 0;
}