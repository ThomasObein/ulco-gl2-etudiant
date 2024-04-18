import gi
import math
import tictactoe

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk, Gdk

class Gui(Gtk.Window):
    
    def __init__(self):
        super().__init__(title="Tictactoe")
        self.set_size_request (400, 400)

        # main vertical box : drawing area + hbox (label, button1, button2)
        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
        self.add(vbox)

        # drawing area
        self.drawingarea = Gtk.DrawingArea()
        self.drawingarea.add_events(Gdk.EventMask.BUTTON_PRESS_MASK)
        self.drawingarea.connect("draw", self.on_draw)
        self.drawingarea.connect("button-press-event", self.on_area_button_press)
        vbox.pack_start(self.drawingarea, True, True, 0)

        # horizontal box
        hbox = Gtk.Box()
        vbox.pack_end(hbox, False, False, 0)

        # create game (from the C++ module)
        self.jeu = tictactoe.Jeu()
        self.jeu.jouer(1, 1)
        self.jeu.jouer(2, 2)

        # label
        self.label = Gtk.Label(label=self.jeu.getStatus().name)
        hbox.pack_start(self.label, True, True, 0)
    
        # button1
        button1 = Gtk.Button(label="rejouer")
        button1.connect("clicked", self.on_button1_clicked)
        hbox.pack_start(button1, True, True, 0)

        # button2
        button2 = Gtk.Button(label="quitter")
        button2.connect("clicked", self.on_button2_clicked)
        hbox.pack_start(button2, True, True, 0)




    def on_draw(self, widget, context):

        # TODO on_draw
        self.label = Gtk.Label(label=self.jeu.getStatus().name)

        width = widget.get_allocated_width()
        height = widget.get_allocated_height()

        # Affichage des cases
        for i in range(0, 3):
            for j in range(0, 3):
                context.set_source_rgb(0, 0, 0)
                context.rectangle(i * 100, j * 100, 100, 100)
                context.fill()
                if self.jeu.getCell(i, j).name == "Rouge":
                    context.set_source_rgb(255, 0, 0)
                    context.arc(i * 100 + 50, j * 100 + 50, 50, 0, 2 * math.pi)
                    context.fill()
                elif self.jeu.getCell(i, j).name == "Vert":
                    context.set_source_rgb(0, 255, 0)
                    context.arc(i * 100 + 50, j * 100 + 50, 50, 0, 2 * math.pi)
                    context.fill()

        # Affichage des lignes
        context.set_source_rgb(0.5, 0.5, 0.5)
        context.set_line_width(3)
        context.move_to(100, 0)
        context.line_to(100, 300)
        context.stroke()

        context.move_to(200, 0)
        context.line_to(200, 300)
        context.stroke()

        context.move_to(0, 100)
        context.line_to(300, 100)
        context.stroke()

        context.move_to(0, 200)
        context.line_to(300, 200)
        context.stroke()


    def on_area_button_press(self, widget, event):
        # TODO on_area_button_press
        if event.button == 1:
            print('TODO on_area_button_press')
            

    def on_button1_clicked(self, widget):
        self.jeu.raz()
        self.drawingarea.queue_draw()

    def on_button2_clicked(self, widget):
        Gtk.main_quit()

if __name__ == '__main__':
    gui = Gui()
    gui.connect("destroy", Gtk.main_quit)
    gui.show_all()
    Gtk.main()

