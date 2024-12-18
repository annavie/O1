// AddSlideCommand.cpp
#include "AddSlideCommand.h"
#include "Editor.h"
#include "Slide.h" // Ensure Slide.h is included
#include <memory>

void AddSlideCommand::execute(Editor& editor) {
    // Create a new Slide instance
    auto newSlide = std::make_unique<Slide>();

    // Add the new slide to the document
    editor.getDocument().addSlide(std::move(newSlide));
}

void AddSlideCommand::undo(Editor& editor) {
    // Get the current number of slides
    size_t slideCount = editor.getDocument().getSlideCount();

    // Ensure there is at least one slide to delete
    if (slideCount > 0) {
        // Delete the last slide (slides are zero-indexed)
        editor.getDocument().deleteSlide(slideCount - 1);
    }
}
