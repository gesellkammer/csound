<CsTest>
description = "exitnow during realtime instrument init does not corrupt the stack"
args = []

[expect]
exit = 2
stderr_regex = ['exitnow init exit']
</CsTest>
<CsoundSynthesizer>
<CsOptions>
-odac -+rtaudio=null --realtime -d -m128
</CsOptions>
<CsInstruments>
sr = 44100
ksmps = 64
nchnls = 1
0dbfs = 1

; In realtime, instrument init runs on the event (alloc queue) thread, so a
; constant-argument exitnow is init-time there. It used to longjmp across
; threads into the performance thread's frame and abort with a stack smashing
; error. The exit status proves the jump still happened and was reported.
instr 1
  a = 0.5*sin(2*3.14159265*440*timeinsts())
  fout "realtime-exitnow-source.wav", 14, a
endin

instr 2
  a1 diskin2 "realtime-exitnow-source.wav", 1, 0, 4096, 0, 2, 1024, 0, 0
  out a1
endin

instr 3
  prints "exitnow init exit\n"
  exitnow(2)
endin
</CsInstruments>
<CsScore>
i1 0 0.4
i2 0.5 1.0
i3 1.0 0.1
</CsScore>
</CsoundSynthesizer>
