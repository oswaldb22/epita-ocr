# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <gtk/gtk.h>

#include "includes.h"
#include "bwMatrix.h"
#include "quicktests.h"
#include "load_to_bw.h"
#include "rgbMatrix.h"
#include "neuralNetwork.h"





int main(int argc, char **argv)
{
    GtkBuilder *builder;
    GtkWidget  *window;
    GError     *error = NULL;

    //Initialise
    gtk_init( &argc, &argv );

    //Create a builder
    builder = gtk_builder_new();

    //Load if error quit application
    if(!gtk_builder_add_from_file( builder, "interfaceg2.glade", &error))
    {
        g_warning( "%s", error->message );
        g_free( error );
        return(1);
    }

    window = GTK_WIDGET(gtk_builder_get_object(builder, "MainWindow"));

    //Connect signals
    gtk_builder_connect_signals(builder, NULL);

    //Destroy useless builder
    g_object_unref(G_OBJECT( builder));

    //Show window
    gtk_widget_show_all(window);

    // Start main loop
    gtk_main();

    return(0);
}


void on_StartTest_clicked(GtkButton *button, GtkLabel *user)
{
  (void)(button);
  //Lancer les tests
  //Récuperer le text

  //Afficher le text dans le display label
  gchar *test = "Lorem ipsum dolor sit amet, consectetur adipiscing\n\
elit. Ut facilisis, urna vel scelerisque\n\
pulvinar diam quam fini▒us ante. Sed erat mi,\n\
lacinia nec accumsan eu, elementum vel sapien,\n\
Pellentesque auctor leo purus, at porttitor dolor\n\
viverra eget, Duis enim eros, tincidunt in sapien.\n\
Pellentesque auctor leo purus, at porttitor dolor\n\
viverra eget. Duis enim eros, tincidunt in sapien\n\
vel, aliquam porttitor justo. Nam laoreet augue\n\
sit amet fauci▒us pellentesque. Vesti▒ulum\n\
suscipit magna eget ni▒▒ consequat congue. Donec\n\
p▒aretra sollicitudin arcu sit amet varius. Sed\n\
ve▒icula nisi quis orci mollis, id laoreet sem\n\
viverra. P▒asellus sagittis orci diam, vitae\n\
sagittis erat maximus fermentum. Nam ultrices\n\
justo ut masse molestie molestie. Integer\n\
venenatis tristique erat vel consectetur. Aliquam\n\
placerat varius neque vitae luctus. Mauris euismod\n\
efficitur justo non congue. Nullam tincidunt\n\
scelerisque ex at tempus. Nunc cursus feugiat\n\
pellentesque.";
  gtk_label_set_text(user, test);
}

void display(GtkWidget *button, GtkWidget *user)
{
  char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(button));
  gtk_image_set_from_file(GTK_IMAGE(user),filename);
}
