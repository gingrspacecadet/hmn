current notes:
* messages are grouped by author and by timestamp. messages by the same person, within some amount of time (default, say, 5 minutes) will be continuous (like discord). Otherwise, insert a new "title card" (username, profile, timestamp, etc).
* timestamps! very useful things. similar to discord, display the message's time of arrival in current timezone & locale. also provide more detailed data on hover, such as full timestamp.
* timezones should be important. I think users should have their display timezone stored and usable by clients. It'd be nice to see, if you're planning an event, how many people will be up for said event.
* i'm not sure about having display names differ from usernames.
* super-powerful code blocks. syntax highlighting for all languages (probably an extension based system, likely tmLanguage), copying, line numbers, horizontal scrolling. The ability to collapse code blocks is essential. very large blocks might get promoted to files (so one can view them in a similar manner to how discord does it now, in a separate window)
* links will mostly just be plain. markdown link aliasing is supported, but i'm leaning away from previews.
* replies are references to other messages. perhaps the ability to reply to multiple messages at once. the ping system should be more controllable. ping author by default, but also "carbon-copy" ping anybody else
* i hate discord scrolling. it's awful. the client should never scroll for you (unless explicitly asked to). if a new message comes in, put it at the bottom. if the user is at the very bottom of the chat, then it is okay to auto-scroll. ideally, you should be able to save state, so moving between channels puts you back where you were.
* history loading. i'm thinking of an infinite scroll upwards. i dislike how discord cuts you back down to the bottom when you do that though. so that should be fixed
* input box. Ctrl+Enter sends, Enter inserts a newline.
* keyboard shortcuts! there should be many. channel switching, search, jump to thread, focus input, navigate history, etc.
* we should have a custom markdown standard be used. we need at least code blocks and links. more could potentially be added later. it should be toggleable
* we should have minimal autocomplete. imo, it shouldnt override the Enter key, as accidents may happen. Maybe Shift+Enter. Autocomplete users, channels, commands, emoji. It should be extensible though
* any file may be "attached". I think it should be in a separate message. However, it might be nice to be able to embed an image inside a message, with text around it.
* anyone can edit any message they've sent. a message that has been edited will display some sort of marker. potentially, we could display some sort of "diff" of the message.
* search should be very powerful. nice filters, fuzzy search, date ranges, authors, channels, file/code search. You should also be able to jump directly to any message it finds. 
* a sort of "edit history"-esque feature could be nice. So you can see where you last were; it reduces the strain if you need to jump between channels

