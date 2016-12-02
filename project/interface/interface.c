# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <gtk/gtk.h>


// make with : gcc -o interface interface.c $(pkg-config --cflags --libs gtk+-3.0 gmodule-2.0)


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

    
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));

    //Connect signals
    gtk_builder_connect_signals(builder, NULL);

    //Destroy useless builder
    g_object_unref(G_OBJECT( builder));

    //Show window
    gtk_widget_show(window);

    // Start main loop
    gtk_main();
    

    return(0);
}

void getn(GtkFileChooser *filechooserbutton1)
{
  gchar *current = gtk_file_chooser_get_filename( filechooserbutton1);
}

void on_startTest_clicked() (GtkButton *button, gpointer user_data)
{
  //Lancer les tests
  

  //Récuperer le text

  //Afficher le text dans le display label

}
