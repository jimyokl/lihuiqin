
for /f %%i in ('dir /b *') do 
        (
            ren %%i %%i.gif
        )
