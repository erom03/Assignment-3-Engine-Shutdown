# Engine Shutdown

## Objective

Give practice with brute force and recursion in C.

## Story

Your rescue team arrived at the malfunctioning boat, but they are having difficulties stopping the
vessel. The damage is extensive and the engine refuses to cease even when the emergency
shut off switch was engaged.

There are known steps that can be taken to help stop the engine, and the rescue team has
some tools that can also be used to help try to stop the engine. Examples of options include
things like spraying the engine with foam, cutting off the air supply to the engine, and
disconnecting the power from the engine.

We are going to perform all of the actions sequentially. Each one will happen exactly once.
The actions can be performed in any order. Currently, the goal is to drop the temperature of the
engine enough that the engine will cease. For each action we know how much the engine
temperature drops. We also know that an earlier action can increase or decrease the amount
the engine temperature drops.

Determine the event order that creates the best engine temperature decrease after performing
all of them.

## Problem

Given a list of actions that can reduce the temperature of the engine and a list of how much
each action impacts the actions that come after it determine the order in which the action should
be performed to maximize the temperature reduction.

## Input

Input will begin with a line containing a single integer, ***n*** (1 ≤ ***n*** ≤ 11), representing the number of
actions that can be performed. The following line contains ***n*** integers, the ***i***-th representing the
amount of temperature changed by the ***i***-th action. The following ***n*** lines. The ***i***-th line will
contain ***n*** integers, the ***j***-th representing the amount of temperature dropped when performing
the ***i***-th action strictly after the ***j***-th action.

All temperature changes will be in the range of -100,000 to 100,000.

## Output

Output should be a line with ***n*** integers representing the order of the index (1 indexed) of the
actions that maximizes the engine temperature loss. If there are multiple orders of actions, any
**one** of them can be printed.
