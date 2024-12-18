// DeleteSlideCommand.cpp
#include "DeleteSlideCommand.h"
#include "Editor.h"

void DeleteSlideCommand::execute(Editor& editor) {
    // Retrieve the slide to be deleted
    Slide* slide = editor.getDocument().getSlide(slideIndex);

    if (slide) {
        deletedSlide = slide->clone();
        editor.getDocument().deleteSlide(slideIndex);
    }
}
void DeleteSlideCommand::undo(Editor& editor) {
    if (deletedSlide) {
        editor.getDocument().addSlide(std::move(deletedSlide));
    }
}
