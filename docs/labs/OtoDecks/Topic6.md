---
layout: default
title: "Topic 6: GUI libraries and JUCE"
parent: Labs
nav_order: 6
---

# Topic 6: GUI libraries and JUCE

## Overview

Topic 6 introduces the second application of the course, OtoDecks, a DJ application built using the JUCE framework. This topic focuses on:

- Understanding what libraries, frameworks, toolkits, APIs, and GUI libraries are
- Setting up the JUCE framework for application development
- Creating a basic GUI application structure
- Understanding the JUCE component hierarchy

## Key Concepts

### Libraries, Frameworks, Toolkits, and APIs

Before diving into JUCE, it's important to understand some key concepts:

- **Library**: A collection of precompiled routines that a program can use. Libraries are particularly useful for storing frequently used routines because you don't need to explicitly link them to every program that uses them.

- **Framework**: A universal, reusable software environment that provides particular functionality as part of a larger software platform to facilitate the development of software applications. Unlike libraries, which are used as individual components, a framework defines the architecture of your application.

- **Toolkit**: A bundle of libraries and utilities geared towards a specific type of tasks or solving a specific type of problems. It can contain libraries, APIs, IDEs, GUI builders, etc.

- **API (Application Programming Interface)**: A set of rules and protocols for building and interacting with software applications. An API specifies how software components should interact.

- **GUI (Graphical User Interface)**: A type of user interface that allows users to interact with electronic devices through graphical icons and visual indicators, instead of text-based interfaces.

### JUCE Framework

JUCE (Jules' Utility Class Extensions) is a C++ application framework that can be used to develop cross-platform software, particularly audio applications. It provides a wide range of functionality, including:

- GUI components
- Audio processing
- File I/O
- Networking
- And more

JUCE is particularly well-suited for audio applications, making it an excellent choice for our OtoDecks application.

## Implementation Details

### Setting Up JUCE

The first step is to set up the JUCE framework for development:

1. **Download and Install JUCE**: Download the JUCE framework from the official website and install it on your system.

2. **Install Projucer**: Projucer is JUCE's project management tool. It allows you to create and manage JUCE projects.

3. **Create a New Project**: Use Projucer to create a new GUI Application project.

4. **Configure the Project**: Set up the project settings, including the application name, company name, and other details.

5. **Generate the Project Files**: Generate the project files for your preferred IDE (Visual Studio, Xcode, etc.).

### Basic JUCE Application Structure

A basic JUCE application consists of several key components:

#### Main.cpp

The `Main.cpp` file contains the application entry point and creates the application window:

```cpp
#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

class OtoDecksApplication : public JUCEApplication
{
public:
    OtoDecksApplication() {}

    const String getApplicationName() override { return ProjectInfo::projectName; }
    const String getApplicationVersion() override { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override { return true; }

    void initialise(const String& commandLine) override
    {
        mainWindow.reset(new MainWindow(getApplicationName()));
    }

    void shutdown() override
    {
        mainWindow = nullptr;
    }

    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted(const String& commandLine) override
    {
    }

    class MainWindow : public DocumentWindow
    {
    public:
        MainWindow(String name)
            : DocumentWindow(name,
                             Desktop::getInstance().getDefaultLookAndFeel()
                                 .findColour(ResizableWindow::backgroundColourId),
                             DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar(true);
            setContentOwned(new MainComponent(), true);

            centreWithSize(getWidth(), getHeight());
            setVisible(true);
        }

        void closeButtonPressed() override
        {
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION(OtoDecksApplication)
```

#### MainComponent.h

The `MainComponent.h` file defines the main component of the application:

```cpp
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MainComponent : public Component
{
public:
    MainComponent();
    ~MainComponent();

    void paint(Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
```

#### MainComponent.cpp

The `MainComponent.cpp` file implements the main component:

```cpp
#include "MainComponent.h"

MainComponent::MainComponent()
{
    setSize(600, 400);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

    g.setFont(Font(16.0f));
    g.setColour(Colours::white);
    g.drawText("Welcome to OtoDecks!", getLocalBounds(), Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
```

### JUCE Component Hierarchy

JUCE uses a component-based architecture for building GUIs. The key classes in this hierarchy are:

- **Component**: The base class for all JUCE GUI components. It provides basic functionality for positioning, sizing, and drawing components.

- **DocumentWindow**: A window with a title bar, close button, and other standard window features.

- **ResizableWindow**: A window that can be resized by the user.

- **TopLevelWindow**: The base class for windows that appear at the top level of the desktop.

Components can be nested within other components, creating a hierarchical structure. This is similar to how HTML elements can be nested within each other.

## OOP Concepts Demonstrated

Topic 6 introduces several important object-oriented programming concepts:

### Inheritance

The JUCE framework makes extensive use of inheritance. For example, the `MainComponent` class inherits from the `Component` class:

```cpp
class MainComponent : public Component
{
    // ...
};
```

This allows `MainComponent` to inherit all the functionality of the `Component` class, such as the ability to be drawn on the screen and respond to user input.

### Polymorphism

JUCE uses polymorphism to allow components to override the behavior of their parent classes. For example, the `MainComponent` class overrides the `paint` and `resized` methods of the `Component` class:

```cpp
void paint(Graphics&) override;
void resized() override;
```

This allows `MainComponent` to provide its own implementation of these methods, while still being treated as a `Component` by the rest of the application.

### Encapsulation

JUCE components encapsulate their state and behavior. For example, the `MainComponent` class encapsulates the state and behavior of the main component of the application:

```cpp
class MainComponent : public Component
{
public:
    // Public interface
    MainComponent();
    ~MainComponent();
    void paint(Graphics&) override;
    void resized() override;

private:
    // Private implementation details
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
```

The public methods provide the interface for interacting with the component, while the private members encapsulate the implementation details.

### Memory Management

JUCE uses smart pointers (`std::unique_ptr`) for memory management:

```cpp
std::unique_ptr<MainWindow> mainWindow;
```

This ensures that the `MainWindow` object is automatically deleted when the `OtoDecksApplication` object is deleted, preventing memory leaks.

## Key Takeaways

1. **Framework-Based Development**: Using a framework like JUCE can significantly speed up development by providing pre-built components and functionality.

2. **Component-Based Architecture**: JUCE uses a component-based architecture for building GUIs, which allows for modular and reusable code.

3. **Cross-Platform Development**: JUCE allows for cross-platform development, meaning the same code can be compiled for different operating systems.

4. **Object-Oriented Design**: JUCE is designed using object-oriented principles, making it a good fit for C++ development.

5. **Audio Application Development**: JUCE is particularly well-suited for audio applications, providing specialized components and functionality for audio processing.

## Next Steps

The next topic will build upon this foundation by implementing UI controls (buttons and sliders) and audio playback functionality for the OtoDecks application.

## Visual Elements

In the JUCE application, the main window would look like a simple window with the text "Welcome to OtoDecks!" centered in it. The window would have a title bar with the application name, and standard window controls (minimize, maximize, close buttons).

As we progress through the topics, we'll add more components to this window to build the OtoDecks application.
