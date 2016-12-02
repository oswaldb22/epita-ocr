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
  //Lancer les tests
  //Récuperer le text

  //Afficher le text dans le display label
  gchar *test = "Texte reconnu";
  gtk_label_set_text(user,test); 
}

void display(GtkWidget *button, GtkWidget *user)
{
  char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(button));
  gtk_image_set_from_file(GTK_IMAGE(user),filename);
}
