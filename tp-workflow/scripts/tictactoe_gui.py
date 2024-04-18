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

        self.label.set_text(self.jeu.getStatus().name)

        width = widget.get_allocated_width()
        height = widget.get_allocated_height()

        self.case_width = width / 3
        self.case_height = height / 3

        # Affichage des cases
        for j in range(0, 3):
            for i in range(0, 3):
                context.set_source_rgb(0, 0, 0)
                context.rectangle(i * self.case_width, j * self.case_height, self.case_width, self.case_height)
                context.fill()
                if self.jeu.getCell(i, j).name == "Rouge":
                    context.set_source_rgb(255, 0, 0)
                    context.arc(i * self.case_width + self.case_width / 2, j * self.case_height + self.case_height / 2, (self.case_width / 2) - 10, 0, 2 * math.pi)
                    context.fill()
                elif self.jeu.getCell(i, j).name == "Vert":
                    context.set_source_rgb(0, 255, 0)
                    context.arc(i * self.case_width + self.case_width / 2, j * self.case_height + self.case_height / 2, (self.case_width / 2) - 10, 0, 2 * math.pi)
                    context.fill()

        # Affichage des lignes
        context.set_source_rgb(0.5, 0.5, 0.5)
        context.set_line_width(3)
        context.move_to(self.case_width, 0)
        context.line_to(self.case_width, 3 * self.case_height)
        context.stroke()

        context.move_to(2 * self.case_width, 0)
        context.line_to(2 * self.case_width, 3 * self.case_height)
        context.stroke()

        context.move_to(0, self.case_height)
        context.line_to(3 * self.case_width, self.case_height)
        context.stroke()

        context.move_to(0, 2 * self.case_height)
        context.line_to(3 * self.case_width, 2 * self.case_height)
        context.stroke()


    def on_area_button_press(self, widget, event):
        if event.button == 1:
            x = int(event.x // self.case_width)
            y = int(event.y // self.case_height)
            self.jeu.jouer(x, y)
            self.drawingarea.queue_draw()
            

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

