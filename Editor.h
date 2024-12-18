// Editor.hpp
#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "Document.h"
#include "HistoryManager.h"
#include "Command.h"

class Editor {
public:
    Editor(Document& doc)
        : document(doc), historyManager() {}

    void executeCommand(std::unique_ptr<Command> cmd) {
        historyManager.executeCommand(std::move(cmd), *this);
    }

    void undo() {
        historyManager.undo(*this);
    }
    void redo() {
        historyManager.redo(*this);
    }
     Document& getDocument() {
        return document;
    }
    const Document& getDocument() const {
         return document;
     }

private:
    Document& document;
    HistoryManager historyManager;
};

#endif // EDITOR_HPP
